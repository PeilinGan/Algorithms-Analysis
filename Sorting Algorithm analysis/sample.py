def is_healthy(height, weight):
	height = float(height)
	bmi = weight/((height/100)**2)
	if bmi < 18.0 or bmi > 25.0:
		return False
	else:
		return True

def max_profit(lst):
	if len(lst) < 2:
		return 0
	else:
		highest_profit = lst[1] - lst[0]
		for i in range(len(lst) - 1):
			profit = lst[i+1] - lst[i]
			if profit > highest_profit:
				highest_profit = profit
		return highest_profit

print(max_profit([1,2,4,5]))

def remove_this(s1,s2):
	result = s1.replace(s2,'')
	return result

print(remove_this("this is good","is"))