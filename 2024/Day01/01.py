arr1 = []
arr2 = []

file = open("01.txt")


for line in file:
    nums = line.split()
    arr1.append(int(nums[0]))
    arr2.append(int(nums[1]))

file.close()

#region Part 1
arr1.sort()
arr2.sort()
output = 0

for i in range(0, len(arr1)):
    output += abs(arr1[i] - arr2[i])
print(output)
#region Part 2 

output = 0
for num in arr1:
    output += num * arr2.count(num);

print(output)