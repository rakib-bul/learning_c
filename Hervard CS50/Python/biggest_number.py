numbers = [12,13,34,657,43,23,7930]

biggest_number = 0

sort_list = sorted(numbers)

reverse_list = sorted(numbers, reverse= True)

print(sort_list)
print(reverse_list)

size = len(sort_list)
biggest_number = sort_list[size -1]
small_number = reverse_list[size -1]

print("Biggest number is ", biggest_number)
print("Smallest number is ", small_number)

