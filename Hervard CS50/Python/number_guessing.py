import random


guess = 0
attemps = 0
max_attemps = 10
random_number = random.randint(1,100)


print("Welcome to Number guessing game")
print("You have", max_attemps,"attempts. Select a number from 1 to 100")

while(attemps < max_attemps):
    try:
        guess = int(input("Enter your number >> "))
    except ValueError:
        print("Please a vaild number")
        continue
    attemps += 1

    if (guess == random_number):
        print("You have choosen the correct number")
        print("Your number is ", random_number)

    elif(guess < random_number):
        print("You guess is too low. Try again")
    else:
        print("Your guess is too high try again")



if (attemps == max_attemps):
    print("You are out of guess. The number was ", random_number)
    print("Game over")

    

