# ApplicationAPI Integration Guide

## 📂 Files needed
- `ApplicationAPI.dll` – The main dynamic library.
- `ApplicationAPI.lib` – Import library for linking.
- `sdkdriver.dll` - Communication with Drive app.
- `ApplicationAPI.h` – Header file with function declarations.

## 📌 Overview
This project demonstrates how to integrate and use `ApplicationAPI.dll` in a C++ application using **Visual Studio 2022**.  

The project is structured as follows:  
```
/InitApiDemo
│── /InitApiDemo        # Project directory
│    ├── /include       # Header files
│    │    ├── ApplicationAPI.h
│    │
│    ├── /lib           # Library files
│    │    ├── ApplicationAPI.dll
│    │    ├── ApplicationAPI.lib
│    │    ├── sdkdriver.lib
│    │
│    ├── main.cpp
│    ├── pch.cpp
│    ├── pch.h
│    │
│    ├── InitApiDemo.vcxproj  # Project file
│
│── InitApiDemo.sln     # Solution file
│── README.md           # This guide

```

## 🛠 Setup Instructions
### **1️⃣ Project Configuration**
1. **Open Visual Studio 2022** and load the project (`.sln` file) or create a new C++ console application.
2. **Place library files (.dll, .lib, .h)** into proper folders (lib, include).
3. **Configure Include Directories:**
   - **Go to:** `Project Properties → C/C++ → General → Additional Include Directories`
   - **Add:** `$(ProjectDir)include`  
4. **Configure Library Directories:**
   - **Go to:** `Project Properties → Linker → General → Additional Library Directories`
   - **Add:** `$(ProjectDir)lib`  
5. **Link Against `ApplicationAPI.lib`:**
   - **Go to:** `Project Properties → Linker → Input → Additional Dependencies`
   - **Add:** `ApplicationAPI.lib`  

### **2️⃣ Post-Build Event (Copy DLL Automatically)**
To ensure `ApplicationAPI.dll` and `sdkdriver.dll` are always placed next to the executable:  
1. **Go to:** `Project Properties → Build Events → Post-Build Event → Command Line`
2. **Add the following command:**
   ```cmd
   xcopy /Y "$(ProjectDir)lib\ApplicationAPI.dll" "$(OutDir)"
   xcopy /Y "$(ProjectDir)lib\sdkdriver.dll" "$(OutDir)"
   ```
   - This copies `ApplicationAPI.dll` and `sdkdriver.dll` to the output directory after building.

### **3️⃣ Build & Run**
- **Build the project** (`Ctrl + Shift + B`).
- **Run the executable** (`F5` or `Ctrl + F5`).

---

## 🔍 Troubleshooting
### ❌ `ApplicationAPI.dll was not found`
- Ensure `ApplicationAPI.dll` exists in the `/lib` folder.
- Run a **clean build** (`Rebuild Solution`).
- Manually copy `ApplicationAPI.dll` to the output folder.

### ❌ `sdkdriver.dll was not found`
- Ensure `sdkdriver.dll` exists in the `/lib` folder.
- Run a **clean build** (`Rebuild Solution`).
- Manually copy `sdkdriver.dll` to the output folder.

### ❌ Linker error: `unresolved external symbol`
- Verify that **`ApplicationAPI.lib`** is added to **Additional Dependencies**.
- Check that **`ApplicationAPI.h`** is included in the source file.

