# multi
embb multiconnectivity, urllc multicell, embb urllc puncturing
## Installation
### Operating system
`Ubuntu 20.04.4 LTS`
### Environment variables
- `MULTI_DIR`
- `MATLAB_DIR`
### Softwares
#### CMake
##### Version
`cmake version 3.16.3`
#### GNU C++ Compiler
##### Version
`g++ (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0`
#### MATLAB
##### Version
`9.10.0.1851785 (R2021a) Update 6`
##### Products
- MATLAB
#### MOSEK
##### Version
`9.3.20`
##### Instruction
- [Install](https://docs.mosek.com/9.3/install/installation.html#linux)
- Move to `~`
- [License](https://docs.mosek.com/9.3/licensing/quickstart.html#local)
- [Setup](https://docs.mosek.com/9.3/toolbox/install-interface.html)
#### CVX
##### Version
`Version 2.2, Build 1148 (62bfcca) Tue Jan 28 00:51:35 2020`
##### Instruction
- [Install](http://cvxr.com/cvx/doc/install.html)
- Move to `~`
- Execute `vim ~/Documents/MATLAB/startup.m` add `run ~/cvx/cvx_startup.m`
- Setup MATLAB
```
cvx_solver mosek
cvx_solver_settings('MSK_IPAR_OPTIMIZER', 'MSK_OPTIMIZER_FREE_SIMPLEX')
cvx_save_prefs
```
- Verify MATLAB
```
cvx_solver
cvx_solver_settings
```
## Test
`./test_all.sh`
## hello
- `idx` index start 0
- `mli` matlab index start 1
- `ml` matlab
