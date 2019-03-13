# openMP-Matrix-Multiplication
Matrix multiplication using openMP technology. **(~2018-11)**

# How to use

**Step 1** Using Visual Studio IDE open Project Properties -> Configuration Properties -> C/C++ -> Language -> Open MP Support ----> select yes. Preferably do that on all configurations.
![Step 1](https://i.gyazo.com/12526a9ba14cff603b001aaa6242ab1d.png)

**Step 2** Head to Build -> Configuration Manager -> Active solution platform -> <New...> -> x64, copy from Win32.
![Step 2.1](https://i.gyazo.com/efb2803055b57b43947c689276c7df16.png)
![Step 2.2](https://i.gyazo.com/be3c2d0210470bcb8c04f4045bd29c6a.png)
![Step 2.3](https://i.gyazo.com/f0a268ad2b6fb2f98a0cefa9656174b1.png)

**Step 3** On line 12 change matrix sizes and on line 23 the number of threads you want to use. Compile using VS.

![Step 3.1](https://i.gyazo.com/3e0a793f55477d3e0eeeeb13a88b2611.png)
![Step 3.2](https://i.gyazo.com/3bbecce409fa90404e62ba86d0fd1320.png)

# Analysis
Full analysis written in Lithuanian may be found in .docx file.

# What did I learn?
  - Using in parallel multiple cores to process data.
  - Analyse and compare results of tests.
