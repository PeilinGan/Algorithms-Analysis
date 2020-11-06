#pragma once
#include <algorithm>
#include <cstddef>
#include <functional>
#include <queue>
#include <utility>
#include <string>
#include <iostream>
using namespace std;

namespace forest {

template <typename T> class AVLTree;

template <typename T> class AVLTreeNodeBase {
  template <typename U> friend class AVLTree;

private:
  T *mLeft{nullptr};
  T *mRight{nullptr};


private:
  std::size_t mHeight{1};

public:
  AVLTreeNodeBase() = default;
  ~AVLTreeNodeBase() = default;
  AVLTreeNodeBase(const AVLTreeNodeBase &other) { mHeight = other.mHeight; }
  AVLTreeNodeBase(AVLTreeNodeBase &&other) {
    mHeight = other.mHeight;
    other.mHeight = 1;
  }

public:
  AVLTreeNodeBase &operator=(const AVLTreeNodeBase &other) {
    if (&other == this)
      return *this;
    mHeight = other.mHeight;
    return *this;
  }
  AVLTreeNodeBase &operator=(AVLTreeNodeBase &&other) {
    if (&other == this)
      return *this;
    mHeight = other.mHeight;
    other.mHeight = 1;
    return *this;
  }




};

class FFNode : public forest::AVLTreeNodeBase<FFNode> {
public:
  FFNode() = default;
  FFNode(const int new_key, const double rc, const double brc ) : key(new_key), rc(rc), brc(brc){};
  ~FFNode() = default;

public:
  bool operator<(const FFNode &other) const { return key < other.key; }
  bool operator>(const FFNode &other) const { return key > other.key; }
  bool operator=(const FFNode &other) const { return key == other.key; }

public:
  void SetKey(const int new_key) { this->key = new_key; }
  void Setrc(const double  cap) { this->rc = cap; }
  void Setbrc(const double  sub) { this->brc = sub; }
  int getkey(){return key;}
  double get_rc(){return rc;}
  double get_brc(){return brc;}

private:
  int key;
  double rc;
  double brc;
};

class BFNode : public forest::AVLTreeNodeBase<BFNode> {
public:
  BFNode() = default;
  BFNode(const int new_key, const double rc, const double brc ) : key(new_key), rc(rc), brc(brc){};
  ~BFNode() = default;

public:
  bool operator<(const BFNode &other) const 
  { if( rc == other.rc){return key < other.key;} 
  return other.rc > rc ;}
  bool operator=(const BFNode &other) const 
  { return key == other.key && brc == other.brc; 
  }

public:
  void SetKey(const int new_key) { this->key = new_key; }
  void Setrc(const double cap) { this->rc = cap; }
  void Setbrc(const double sub) { this->brc = sub; }
  int getkey(){return key;}
  double get_rc(){return rc;}
  double get_brc(){return brc;}

private:
  int key;
  double rc;
  double brc;
};


template <typename T> class AVLTree {
public:
  using Callback = std::function<void(T &)>;

private:
  T *mRoot{nullptr};

private:
  void PreOrderTraversal(T *root, const Callback &callback) {
    if (!root)
      return;
    callback(*root);
    PreOrderTraversal(root->mLeft, callback);
    PreOrderTraversal(root->mRight, callback);
  }
  void InOrderTraversal(T *root, const Callback &callback) {
    if (!root)
      return;
    InOrderTraversal(root->mLeft, callback);
    callback(*root);
    InOrderTraversal(root->mRight, callback);
  }
  void PostOrderTraversal(T *root, const Callback &callback) {
    if (!root)
      return;
    PostOrderTraversal(root->mLeft, callback);
    PostOrderTraversal(root->mRight, callback);
    callback(*root);
  }
  void BreadthFirstTraversal(T *root, const Callback &callback) {
    if (!root)
      return;
    std::queue<T *> queue;
    queue.push(root);
    while (!queue.empty()) {
      T *current{queue.front()};
      callback(*current);
      queue.pop();
      if (current->mLeft)
        queue.push(current->mLeft);
      if (current->mRight)
        queue.push(current->mRight);
    }
  }

private:
  T *Minimum(T *root) {
    if (!root)
      return nullptr;
    while (root->mLeft)
      root = root->mLeft;
    return root;
  }
  T *Maximum(T *root) {
    if (!root)
      return nullptr;
    while (root->mRight)
      root = root->mRight;
    return root;
  }

private:
  ptrdiff_t Balance(const T *root) {
    if (!root)
      return 0;
    return Height(root->mLeft) - Height(root->mRight);
  }

private:
  std::size_t Height(const T *root) {
    if (!root)
      return 0;
    return root->mHeight;
  }
  std::size_t Size(const T *root) {
    if (!root)
      return 0;
    return Size(root->mLeft) + Size(root->mRight) + 1;
  }

private:
  T *RotateRight(T *root) {
    T *pivot{root->mLeft};
    T *orphan{pivot->mRight};
    pivot->mRight = root;
    root->mLeft = orphan;
    root->mHeight = std::max(Height(root->mLeft), Height(root->mRight)) + 1;
    root->Setbrc(largest_brc(brcval(root->mLeft), root->get_rc(),brcval(root->mRight)));
    pivot->mHeight = std::max(Height(pivot->mLeft), Height(pivot->mRight)) + 1;
    pivot->Setbrc(largest_brc(brcval(pivot->mLeft), pivot->get_rc(),brcval(pivot->mRight)));
    return pivot;
  }
  T *RotateLeft(T *root) {
    T *pivot{root->mRight};
    T *orphan{pivot->mLeft};
    pivot->mLeft = root;
    root->mRight = orphan;
    root->mHeight = std::max(Height(root->mLeft), Height(root->mRight)) + 1;
    root->Setbrc(largest_brc(brcval(root->mLeft), root->get_rc(),brcval(root->mRight)));
    pivot->mHeight = std::max(Height(pivot->mLeft), Height(pivot->mRight)) + 1;
    pivot->Setbrc(largest_brc(brcval(pivot->mLeft), pivot->get_rc(),brcval(pivot->mRight)));
    return pivot;
  }

private:
  T *Insert(T *root, const T &node) {
    if (!root)
      return new T(node);
    if (node < *root)
      root->mLeft = Insert(root->mLeft, node);
    else if (*root < node)
      root->mRight = Insert(root->mRight, node);
    root->mHeight = std::max(Height(root->mLeft), Height(root->mRight)) + 1;
    root->Setbrc(largest_brc(brcval(root->mLeft), root->get_rc(),brcval(root->mRight)));    if (Balance(root) > 1) {
      if (node < *root->mLeft) {
        return RotateRight(root);
      } else if (*root->mLeft < node) {
        root->mLeft = RotateLeft(root->mLeft);
        return RotateRight(root);
      }
    } else if (Balance(root) < -1) {
      if (*root->mRight < node) {
        return RotateLeft(root);
      } else if (node < *root->mRight) {
        root->mRight = RotateRight(root->mRight);
        return RotateLeft(root);
      }
    }
    return root;
  }



  template <typename Key> T *Remove(T *root, const Key &key) {
    if (!root)
      return nullptr;
    if (key < *root)
      root->mLeft = Remove(root->mLeft, key);
    else if (*root < key)
      root->mRight = Remove(root->mRight, key);
    else {
      if (!root->mLeft && !root->mRight) {
        delete root;
        root = nullptr;
      } else if (!root->mLeft) {
        T *tmp{root};
        root = root->mRight;
        delete tmp;
        tmp = nullptr;
      } else if (!root->mRight) {
        T *tmp{root};
        root = root->mLeft;
        delete tmp;
        tmp = nullptr;
      } else {
        T *min{Minimum(root->mRight)};
        *root = *min;
        root->mRight = Remove(root->mRight, *min);
      }
    }
    if (!root)
      return nullptr;
    root->mHeight = std::max(Height(root->mLeft), Height(root->mRight)) + 1;
    // rebalance the tree
    root->Setbrc(largest_brc(brcval(root->mLeft), root->get_rc(),brcval(root->mRight)));
    if (Balance(root) > 1) {
      if (Balance(root->mLeft) >= 0) {
        return RotateRight(root);
      }
      root->mLeft = RotateLeft(root->mLeft);
      return RotateRight(root);
    } 
    else if (Balance(root) < -1) {
      if (Balance(root->mRight) <= 0) {
        return RotateLeft(root);
      }
      root->mRight = RotateRight(root->mRight);
      return RotateLeft(root);
    }
    return root;
  }
  template <typename Key> T *Search(T *root, const Key &key) {
    while (root) {
      if (*root < key) {
        root = root->mRight;
      } else if (key < *root) {
        root = root->mLeft;
      } else {
        return root;
      }
    }
    return nullptr;
  }

private:
  void Clear(T *root) {
    if (!root)
      return;
    if (root->mLeft)
      Clear(root->mLeft);
    if (root->mRight)
      Clear(root->mRight);
    delete root;
    root = nullptr;
  }
public:
  AVLTree() = default;
  ~AVLTree() { Clear(); }
  AVLTree(const AVLTree &) = delete;
  AVLTree(AVLTree &&other) {
    mRoot = other.mRoot;
    other.mRoot = nullptr;
  }
private:
  double brcval(T * node)
  {
    if(node == nullptr)
    {
      return 0.0;
    }
    return node->get_brc();
  }
  double largest_brc(double left, double root, double right) 
  {
    if (left > root) 
    {
      if (left > right)
      {
        return left;
      }
      return right;              
    }
    else 
    {
      if (root > right)
      {
        return root;
      }
      return right;
    }
  }
public:
  AVLTree &operator=(const AVLTree &) = delete;
  AVLTree &operator=(AVLTree &&other) {
    if (&other == this)
      return *this;
    mRoot = other.mRoot;
    other.mRoot = nullptr;
    return *this;
  }

private:
  T BFtraverse(T * node, double weight)
  {
    if (node == nullptr || node->get_brc() < weight)
    {
      
        T n;
        n.SetKey(-100);
        n.Setrc(-100.0);
        n.Setbrc(-100.0);
        return n;
      
    }
    if (node->mLeft != nullptr)
    {
      if(node->mLeft->get_brc() >= weight)
      {
        //traverse left first
        return BFtraverse(node->mLeft, weight);
      }
    }
    //if not found, traverse right
    double RC = node->get_rc();
    if(weight <= RC)
    {
        int key = node->getkey();
        double rc = node->get_rc();
        double brc = node->get_brc();
        return T(key, rc, brc);
    }
    return BFtraverse(node->mRight, weight);
  }

  int FFtraverse(T *node, double weight)
  {
    //return the node index (key)
    int first_bin;
    if (node == nullptr || node->get_brc() < weight) 
    {
        return -1;
    }

    if (node->mLeft != nullptr && weight <= node->mLeft->get_brc())
    {
        first_bin=FFtraverse(node->mLeft, weight);
        node->Setbrc(largest_brc(brcval(node->mLeft), node->get_rc(),brcval(node->mRight)));
   
    } 
    else 
    {
        if (node->get_rc() < weight)  
        {
            first_bin=FFtraverse(node->mRight, weight);
            node->Setbrc(largest_brc(brcval(node->mLeft), node->get_rc(),brcval(node->mRight)));
        }
        
        else 
        {
            double diff = node->get_rc() - weight;
            node->Setrc(diff);
            node->Setbrc(largest_brc(brcval(node->mLeft), node->get_rc(),brcval(node->mRight)));
            int best_bin = node->getkey();
            first_bin = best_bin;
        } 
    }
    return first_bin;
    
  }

public: 
  int BFpack(double weight)
  {
      T Bestbin = BFtraverse(mRoot, weight);
      if (Bestbin.getkey() < 0) 
      {
        return -1;
      }
      else
      {
        // remove first
        this->Remove(Bestbin);
        double diff = Bestbin.get_rc() - weight;
        Bestbin.Setrc(diff);
        Bestbin.Setbrc(diff);
        // then insert
        this -> insert(Bestbin);
        int best_key = Bestbin.getkey();
        return best_key;
      }
  }
  void insert(const T & new_node) 
  { 
    mRoot = Insert(mRoot, new_node); 
  }

public:
  void PreOrderTraversal(const Callback &callback) {
    PreOrderTraversal(mRoot, callback);
  }
  void InOrderTraversal(const Callback &callback) {
    InOrderTraversal(mRoot, callback);
  }
  void PostOrderTraversal(const Callback &callback) {
    PostOrderTraversal(mRoot, callback);
  }
  void BreadthFirstTraversal(const Callback &callback) {
    BreadthFirstTraversal(mRoot, callback);
  }
  int FFtraverse(double weight){return FFtraverse(mRoot, weight);}

public:
  T *Minimum() { return Minimum(mRoot); }
  T *Maximum() { return Maximum(mRoot); }
  double Largestrc(){return mRoot->get_brc();}

public:
  std::size_t Height() { return Height(mRoot); }
  std::size_t Size() { return Size(mRoot); }


public:
  template <typename Key> void Remove(const Key &key) {
    mRoot = Remove(mRoot, key);
  }
  template <typename Key> T *Search(const Key &key) {
    return Search(mRoot, key);
  }

public:
  void Clear() {
    Clear(mRoot);
    mRoot = nullptr;
  }
};
} // namespace forest