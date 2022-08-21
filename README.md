# C projectr repository

## Struct example

### On the Single file

### On the Multiple files

There is some problem with this case. I guess it's a complile error. To resolve this problem, there are 2 solutions. 

![image](https://user-images.githubusercontent.com/71545160/185779124-809a79e8-9db8-488e-a3b9-f27c104e76ef.png)

* **First Solution** :  Compling manually like below. 
  ```C
    gcc -o main main.c struct_ex.c
  ```
![image](https://user-images.githubusercontent.com/71545160/185779171-05756d66-efbc-430c-b88b-dcfc6777fd6b.png)

Then you can obtain **.exe** file like below. And just run in terminal, then you can obtain second figure result.

![image](https://user-images.githubusercontent.com/71545160/185779254-4076cbc8-9039-4e77-9a83-8bf1ca4195f0.png)
![image](https://user-images.githubusercontent.com/71545160/185779271-bdf98fbb-d54a-49c8-a099-59ef984d33bb.png)

* **Second Solution** : Include source file on the **main.c**  or, include the target function on the **struct_ex.h**.
 ```C
    #include "struct_ex.c"
  ```
Then you can obtain same result with above.

<br>

-----------------------

<br>

## Data load from CSV file example
