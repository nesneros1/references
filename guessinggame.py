import random
r = random.randint(0,10)
tries = 2
while tries >=0:
    print("Guess the number, 1 to 10") 
    guess = int(input(("Enter your guess:::")))
    if guess == r:
        print("You guessed correctly")
        break
    else:
        print("Not quite, try again")
        print(f'You have {tries} tries left')
        tries -= 1
print("Game over ;(")
