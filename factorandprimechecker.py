#Factorization
print("Checking for factors")
number = int(input("Enter your number:::"))
factors= []
range = range(1,number)
for i in range:
    if number % i == 0:
        factors.append(i)
if len(factors) < 2:
    print('Number is prime!')
else:
    print(factors)
