'''
string = input("Enter string\n")


s2 = string.strip()
s3 = s2.replace('x','a')
s4 = s3.replace('^','s')
print(s4)


from datetime import date
today = date.today()
day = today.weekday()


print(f'Today is {today}. It is day {day} of the week')




my_list = []
for i in range(1,5050505,23):
    my_list.append(i)
oddlist= []
for i in my_list:
   if i % 2 != 0:
       oddlist.append(i)
print(sum(oddlist))




numbers = range(3,5000)
list = []
for i in numbers:
   if i %5 == 0 and i %7 == 0:
       continue
   elif i %5 == 0 or i %7 == 0:
       list.append(i)
       
print(sum(list))




type = input('Is your number decimal, hexadecimal, or binary?\n')
number = input('Enter your number\n')


def binary(number):
   base10 = int(number,2)
   base16 = hex(int(number,2))
   print(f'Decimal = {base10}\nHex = {base16.replace("0x","")}')


def decimal(number):
   base2 = bin(int(number))
   base16 = hex(int(number))
   print(f'Binary = {base2.replace("0b","")}\nHex = {base16.replace("0x","")}')


def hexadecimal(number):
   base10 = int(number, 16)
   base2 = bin(int(number,16))
   print(f'Decimal = {base10}\nBinary= {base2.replace("0b","")}')



if type == 'binary':
   binary(number)
elif type == 'decimal':
   decimal(number)
else:
   hexadecimal(number)


#astrology



birthday = input("When is your birthday? Use MM/DD format\n")
dinm = [0,31,28,31,30,31,30,31,31,30,31,30]
def conversion(birthday):
   mm, dd = birthday.split('/')
   length = len(dinm)
   listsum = 0
   for i in range(int(mm)):
       listsum += dinm[i]
   total = listsum + int(dd)
   return total


06/19


bday = conversion(birthday)
if bday >= 80 and bday <= 109:
   print("aries")
elif bday >=110 and bday <= 140:
   print("taurus")
elif bday >=141 and bday <= 171:
   print("gemini")
elif bday >=172 and bday <= 203:
   print("cancer")
elif bday >=204 and bday <= 234:
   print("leo")
elif bday >=235 and bday <= 265:
   print("virgo")
elif bday >=267 and bday <= 295:
   print("libra")
elif bday >=296 and bday <= 325:
   print("scorpio")
elif bday >=326 and bday <= 355:
   print("saggitarius")
elif bday >= 356 or bday <= 20:
   print('capricorn')
elif bday >=21 and bday <= 49:
   print("aquiarius")
elif bday >=50 and bday <= 79:
   print("pisces")






string = input('Enter a string\n')
for i in range(0,len(string)):
   print(f'{string[i]}\t\U00002620')




string = input("enter a string to look for root\n")
def search(string):
   for i in range(0,len(string)+1):
       searched = string[i:i+4]
       if searched == 'root':
           return searched
           break
if search(string) == 'root':
   print(f'found')






dict1 = {  "xxlx":"xx!xx",
   "xfx":"ExLx",
   "0":'xSx',
    "www.":"SxQxUxIxRxRx",
    "python.org":'xRxExT',
    "pickle rick":'ExC' }
keylist = []
valuelist=[]
for key, value in dict1.items():
   keylist.append(key)
keylist.sort()
print(keylist)
for i in keylist:
   for key, value in dict1.items():
       if i == key:
           valuelist.append(value)
valuelist = str(valuelist)
stringy=' '
for x in valuelist:
   stringy += ' '+x
print(stringy)


text = 'root:x:0:0:root:/root:/bin/ash bin:x:1:1:bin:/bin:/sbin/nologin daemon:x:2:2:daemon:/sbin:/sbin/nologin adm:x:3:4:adm:/var/adm:/sbin/nologin lp:x:4:7:lp:/var/spool/lpd:/sbin/nologin sync:x:5:0:sync:/sbin:/bin/sync'
x = text.replace(' ',':')
y = x.split(":")
userlist = y[::7]
defaultshell = y[6::7]
homedir = y[5::7]
for i in range(0,len(userlist)):
   print(f'USER: {userlist[i]}\nDEFAULT SHELL: {defaultshell[i]}\nHOME DIRECTORY: {homedir[i]}')






my_list = list()
for i in range(1,5050505,23):
    my_list.append(i)
print(max(my_list) - min(my_list))




dict1 = {  "xxlx":"xx!xx",
   "xfx":"ExLx",
   "0":'xSx',
    "www.":"SxQxUxIxRxRx",
    "python.org":'xRxExT',
    "pickle rick":'ExC' }
tofind = input("What is the key called?")
print('The key is in the file::')
print(tofind in dict1)


my_list = list()
for i in range(1,5050505,23):
   if i % 2 != 0:
       my_list.append(i)
print(sum(my_list))


string = (input("Enter string\n"))
listin = string.split()
print(listin)
def organizer(listin):
   for i in listin:
       i = sorted(i)
       print(i[0])
organizer(listin)


string = (input("Enter string\n"))
listin = string.split()
joined = ''.join( i for i in listin )
unique = []
for i in joined:
   if i not in unique:
       unique.append(i)
unique.sort()
print(''.join(i for i in unique))


#facotrial of 17
total = 1
for i in range(1,18):
   total = total*i
print(total)


total = 0
for i in range(3,5000):
   if i % 5 == 0 and i %7 == 0:
       continue
   elif i % 5 == 0 or i %7 == 0:
       total += i
print(total)




def triangle(base, character):
   height = 0
   for i in range(0,base+2):
       if i % 2 != 0:
           print((' ')*int((base-i)/2 +5), character*i)
           height += 1
   print(f'Hieght = {height}')
base = int(input('Enter the size of the base.\n'))
character = input("Enter the character you would like to use.\n")
triangle(base, character)


h = int(input("enter height"))
w = int(input('enter width'))
def boxmaker(h,w):
   middle = ' '*(w-2)
   for i in range(1,h+1):
       if i == 1:
           print('*'*w)
       elif i < h:
           print(f'*{middle}*')
       elif i == h:
           print('*'*w)
boxmaker(h,w)
'''

CLASSES

from datetime import date




class Person():
   from datetime import date
   def __init__(self,first,last,bday):
       self.first = first
       self.last = last
       self.bday = bday
   def birthday(self):
       return f'{self.bday}'
   def fullname(self):
       return f'{self.first} {self.last}'
   def astrology(self):
       birthday = self.bday
       dinm = [0,31,28,31,30,31,30,31,31,30,31,30]
       yy, mm, dd = birthday.split('/')
       length = len(dinm)
       listsum = 0
       for i in range(int(mm)):
           listsum += dinm[i]
           total = listsum + int(dd)
       bday = total
       if bday >= 80 and bday <= 109:
           return ("aries")
       elif bday >=110 and bday <= 140:
           return ("taurus")
       elif bday >=141 and bday <= 171:
           return ("gemini")
       elif bday >=172 and bday <= 203:
           return ("cancer")
       elif bday >=204 and bday <= 234:
           return ("leo")
       elif bday >=235 and bday <= 265:
           return ("virgo")
       elif bday >=267 and bday <= 295:
           return ("libra")
       elif bday >=296 and bday <= 325:
           return ("scorpio")
       elif bday >=326 and bday <= 355:
           return ("saggitarius")
       elif bday >= 356 or bday <= 20:
           return ('capricorn')
       elif bday >=21 and bday <= 49:
           return ("aquiarius")
       elif bday >=50 and bday <= 79:
           return ("pisces") 
   def calculateAge(self):
       self = self.bday
       yy, mm, dd = self.split('/')
       birthDate = (date(int(yy),int(mm),int(dd)))
       days_in_year = 365.2425  
       age = int((date.today() - birthDate).days / days_in_year)
       return age
   def __str__(self):
       return f"""
       NAME : {self.first} {self.last}
       ASTRO: {self.astrology()}
       AGE  : {self.bday}      
       """
       
class Student(Person):
   def __init__(self, first,last,bday,id,*grades):
       super().__init__(first,last,bday)
       self.id = id
       self.grades = grades
   def GPA(self):
       total = 0
       for i in self.grades:
           total += i
       return total/len(self.grades)


   def __str__(self):
       return f"""
       NAME : {self.first} {self.last}k
       ASTRO: {self.astrology()}
       AGE  : {self.bday}
       GPA  : {self.GPA()}
       ID   : {self.id}     
       """
  
          


'''
student1=Student('Connor','Sorensen','200/06/19','4553426',[90,68,83])   
person1 = Person('Connor','Sorensen','2000/06/19')
print(person1.astrology())
print(person1.calculateAge())
print(student1.GPA())
'''


nick = Student("Nick","Wylds","1991/10/29",'6541',0,12,50,100,50,100,100)
bob = Person('Bob','Smith','1989/02/14')
print(nick.astrology(),nick.calculateAge())
list_of_info = nick
print(list_of_info)
#print(bob)
