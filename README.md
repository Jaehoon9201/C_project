# C projectr repository

## Struct example

### On the Single file

> <U>structure_ex_singlefile</U>

### On the Multiple files

There is some problem with this case. I guess it's a complile error. To resolve this problem, there are 2 solutions. 

![image](https://user-images.githubusercontent.com/71545160/185779124-809a79e8-9db8-488e-a3b9-f27c104e76ef.png)

* **First Solution** :  Compling manually like below. 

 > <U>structure_ex_multifile_GCCsetting</U>

  ```C
    gcc -o main main.c struct_ex.c
  ```
![image](https://user-images.githubusercontent.com/71545160/185779171-05756d66-efbc-430c-b88b-dcfc6777fd6b.png)

Then you can obtain **.exe** file like below. And just run in terminal, then you can obtain second figure result.

![image](https://user-images.githubusercontent.com/71545160/185779254-4076cbc8-9039-4e77-9a83-8bf1ca4195f0.png)
![image](https://user-images.githubusercontent.com/71545160/185779271-bdf98fbb-d54a-49c8-a099-59ef984d33bb.png)

* Second Solution : Include source file on the **main.c**  or, include the target function on the **struct_ex.h**.

> <U>structure_ex_multifile_SourceInclude</U>

 ```C
    #include "struct_ex.c"
  ```
Then you can obtain same result with above.

<br>

-----------------------

<br>

## Data load from CSV file example

### Our target(to be loaded) .CSV file

24 rows, 7 columns data file

![image](https://user-images.githubusercontent.com/71545160/185780305-d28bfed4-92b6-4694-8932-9750cf1b7734.png)

### Data load result with **dataload.c** file

![image](https://user-images.githubusercontent.com/71545160/185780287-c6bbc009-0814-43b9-be7d-0a28f2b5ba94.png)

<br>

-----------------------

<br>

## TC3xx_EvalBrd_Basic_SequenceRun_wScript.zip

### Setting

1. Intall python ( above 3.7 ver )

2. Intall Isystem python library
 
![image](https://user-images.githubusercontent.com/71545160/237033166-a5e639c3-eb8b-4af4-832b-046dc177602b.png)

3. python script path - user setting

![image](https://user-images.githubusercontent.com/71545160/237032837-cda5155a-a5b2-473f-8938-ddffebc32558.png)


### Example

- changing 'tester3' from default to 5 and to 6 sequencially.

```c
  # This script is licensed under BSD License, see file LICENSE.txt.
  #
  # (c) iSYSTEM Labs d.o.o., 2023

  import isystem.connect as ic


  def test_modify():
      connMgr = ic.ConnectionMgr()
      connMgr.connectMRU('')

      dataCtrl = ic.CDataController(connMgr)

      print(f"Modify variable 'tester3' to value '5'...")
      dataCtrl.modify(ic.IConnectDebug.fRealTime, "tester3", "5", False)
      print(f"Modify variable 'tester3' to value '6', with read-back...")
      value = dataCtrl.modify(ic.IConnectDebug.fRealTime, "tester3", "6", True)
      print(f"\tRead-back value: {value}")


      for i in range(10000):
          print("")

  if __name__ == "__main__":
      test_modify()
```


- **CAUTION:** Be sure to properly indent the lines with the text editor. I tried to match it with notepad, but it is not recognized by oneEye. (actually, if you open it in Notepad, the line is misaligned)

![image](https://github.com/Jaehoon9201/C_project/assets/71545160/554fd3e2-2ec0-4276-ae44-ade2c6697958)
