import re

with open("input.txt", 'r') as file:
    corrupted = file.read()

mul_pattern = r"mul\((\d+),(\d+)\)" 
do_pattern = r"do\(\)"
dont_pattern = r"don't\(\)"


enabled = True  
total = 0

tokens = re.split(r"(do\(\)|don't\(\))", corrupted)

for token in tokens:
    token = token.strip()
    if re.match(do_pattern, token):
        enabled = True
    elif re.match(dont_pattern, token):
        enabled = False
    else:
        matches = re.findall(mul_pattern, token)
        if enabled:
            for x, y in matches:
                total += int(x) * int(y)
        
print(total);
