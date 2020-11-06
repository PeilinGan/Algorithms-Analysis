#include "project2.h"

void create_csv_file(string filename)
{
    ofstream f;
    f.open(filename, ios::trunc);
    f << "n,waste\n";
    f.close();
}

void add_waste_to_file(int size,double waste, string filename)
{
    ofstream f;
    f.open(filename, ios::app);
    f << size << "," << waste << "\n";
    f.close();
}

vector<double> item_generator(int size)
{
	vector<double> items;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 generator = mt19937(seed);

	uniform_real_distribution<> dis(0.0,1.0);
	//Draw double from distribution, if get an zero, draw again.
	for(int i =0; i< size; i++)
	{
		double item = dis(generator);
		while(item == 0.0)
		{
			item = dis(generator);
		}
		items.push_back(item);
	}
	return items;
} 

double waste(const vector<double> & free_space)
{
	double sum = 0;
	for(int i =0; i< free_space.size();i++)
	{
		sum += free_space[i];
	}
	return sum;
}

int main()
{
	
	cout<< "------------------ Test Next Fit correctness ------------------"<<endl;
	vector<double> nf_items{0.50,0.70,0.50,0.20,0.40,0.20,0.50,0.10,0.60};
	vector<int> nf_assignment(nf_items.size(),0);
	vector<double> nf_free_space;
	next_fit(nf_items,nf_assignment,nf_free_space);
	cout<< "Result :        "<<' ';
	for(int i= 0;i < nf_assignment.size(); i++)
	{
		cout<< nf_assignment[i]<<' ';
	}
	cout<< endl;
	cout<<"Correct Result : 0 1 2 2 3 3 4 4 5"<<endl;
	
	cout<< "------------------ Test First Fit correctness ------------------"<<endl;

	vector<double> ff_items{0.50,0.70,0.50,0.20,0.40,0.20,0.50,0.10,0.60};
	vector<int> ff_assignment(ff_items.size(),0);
	vector<double> ff_free_space;
	first_fit(ff_items,ff_assignment,ff_free_space);
	cout<< "Result :        "<<' ';
	for(int i= 0;i < ff_assignment.size(); i++)
	{
		cout<< ff_assignment[i]<<' ';
	}
	cout<< endl;
	cout<<"Correct Result : 0 1 0 1 2 2 3 1 4"<<endl;
		

	cout<< "------------------ Test First Fit decreasing correctness ------------------"<<endl;

	vector<double> ffD_items{0.53,0.71,0.60,0.43,0.76,0.85,0.13,0.69,0.68,0.33,0.18,0.67,0.98,0.75,0.28,0.39};
	vector<int> ffD_assignment(ffD_items.size(),0);
	vector<double> ffD_free_space;
	first_fit_decreasing(ffD_items,ffD_assignment,ffD_free_space);
	cout<< "Result :        "<<' ';
	for(int i= 0;i < ffD_assignment.size(); i++)
	{
		cout<< ffD_assignment[i]<<' ';
	}
	cout<< endl;
	cout<<"Correct Result : 9 4 8 9 2 1 1 5 6 10 2 7 0 3 4 8 "<<endl;

	

	cout<< "------------------ Test Best Fit correctness ------------------"<<endl;

	vector<double> bf_items{0.50,0.70,0.50,0.20,0.40,0.20,0.50,0.10,0.60};
	vector<int> bf_assignment(bf_items.size(),0);
	vector<double> bf_free_space;
	best_fit(bf_items,bf_assignment,bf_free_space);
	cout<< "Result :        "<<' ';
	for(int i= 0;i < bf_assignment.size(); i++)
	{
		cout<< bf_assignment[i]<<' ';
	}
	cout<< endl;
	cout<<"Correct Result : 0 1 0 1 2 2 3 1 4"<<endl;

	cout<< "------------------ Test Best Fit Decreasing correctness ------------------"<<endl;

	vector<double> bf_itemsD{0.53,0.71,0.60,0.43,0.76,0.85,0.13,0.69,0.68,0.33,0.18,0.67,0.98,0.75,0.28,0.39};
	vector<int> bf_assignmentD(bf_itemsD.size(),0);
	vector<double> bf_free_spaceD;
	best_fit_decreasing(bf_itemsD,bf_assignmentD,bf_free_spaceD);
	cout<< "Result :        "<<' ';
	for(int i= 0;i < bf_assignmentD.size(); i++)
	{
		cout<< bf_assignmentD[i]<<' ';
	}
	cout<< endl;
	cout<<"Correct Result : 9 4 8 9 2 1 1 5 6 10 2 7 0 3 4 8 "<<endl;
	

	cout<< "------------------ Test First Fit optimized correctness ------------------"<<endl;

	vector<double> test_items{0.72,0.10,0.35,0.23,0.53,0.71,0.60,0.43,0.76,0.85,0.13,0.69,0.687,0.120,0.178,0.667,0.928,0.120};
	vector<int> test_assignment(test_items.size(),0);
	vector<double> test_free_space;
	first_fit(test_items,test_assignment,test_free_space);
	cout<< "Result of first fit           :       "<<' ';
	for(int i= 0;i < test_assignment.size(); i++)
	{
		cout<< test_assignment[i]<<' ';
	}
	cout<< endl;
	vector<int> test_assignment_op(test_items.size(),0);
	test_free_space.clear();
	first_fit_optimized(test_items,test_assignment_op,test_free_space);
	cout<< "Result of first fit optimized:        "<<' ';
	for(int i= 0;i < test_assignment.size(); i++)
	{
		cout<< test_assignment[i]<<' ';
	}
	cout<< endl;
	


	
	// -----------------------------Empirical test----------------------------------
	std::vector<int> sizes;
	for(int i = 100; i< 100000;i += 100)
	{
		sizes.push_back(i);
	}
	create_csv_file("NF.csv");
	create_csv_file("FF.csv");
	create_csv_file("BF.csv");
	create_csv_file("FF_D.csv");
	create_csv_file("BF_D.csv");


	for(int i =0; i < sizes.size();i++)
	{
		vector<double> items = item_generator(sizes[i]);

		vector<int> NF_assignment(items.size(), 0);
		vector<double> free_space;
		next_fit(items,NF_assignment,free_space);
		double w = waste(free_space);
		add_waste_to_file(sizes[i],w, "NF.csv");
		free_space.clear();

		vector<int> FF_assignment(items.size(), 0);
		first_fit(items,FF_assignment,free_space);
		w = waste(free_space);
		add_waste_to_file(sizes[i],w, "FF.csv");
		free_space.clear();

		vector<int> BF_assignment(items.size(), 0);
		best_fit(items,BF_assignment,free_space);
		w = waste(free_space);
		add_waste_to_file(sizes[i],w, "BF.csv");
		free_space.clear();

		vector<int> FF_D_assignment(items.size(), 0);
		first_fit_decreasing(items,FF_D_assignment,free_space);
		w = waste(free_space);
		add_waste_to_file(sizes[i],w, "FF_D.csv");
		free_space.clear();

		vector<int> BF_D_assignment(items.size(), 0);
		best_fit_decreasing(items,BF_D_assignment,free_space);
		w = waste(free_space);
		add_waste_to_file(sizes[i],w, "BF_D.csv");
	}
	
	

	return 0;
}