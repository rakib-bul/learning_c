x = int(input("Enter first value = "))
y = int(input("Enter Second value = "))


while True:
    task = str(input("Please select task: +|-|*|/ = "))
    valid_operators = ['+', '-', '*', '/', '%', '**']

    if task in valid_operators:
        break
    else:
        print("Invalid operator. Select a valid operator.")

if task == '+':
    print(x+y)
elif task == '-':
    print(x-y)
elif task == '*':
    print(x*y)
elif task == '/':
    print(x/y)
else:
    print("Invalid value")