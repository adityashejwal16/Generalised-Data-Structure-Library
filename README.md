# 🚀 Generalised Data Structure Library (C++)

## 📌 Project Overview

**Generalised Data Structure Library** is a C++ implementation of commonly used data structures using a **Template-based (Generic Programming)** approach.

This project demonstrates how reusable data structure libraries are built internally without using STL containers. The library supports multiple data types such as `int`, `char`, and `double`, making the structures flexible and reusable.

---

## 🎯 Objectives

* Implement fundamental data structures from scratch
* Understand dynamic memory allocation
* Apply Object-Oriented Programming concepts
* Develop reusable generic components using C++ templates
* Strengthen core data structure knowledge

---

## 🧩 Implemented Data Structures

| Data Structure                 |  Description                             |
| ------------------------------ | ---------------------------------------- |
| ✅ Singly Linear Linked List   | One-directional traversal                |
| ✅ Doubly Linear Linked List   | Forward and backward traversal           |
| ✅ Singly Circular Linked List | Last node connects to first              |
| ✅ Doubly Circular Linked List | Circular traversal in both directions    |
| ✅ Stack                       | LIFO (Last In First Out) implementation  |
| ✅ Queue                       | FIFO (First In First Out) implementation |

---

## ⚙️ Features

* Template-based generic implementation
* Dynamic memory allocation
* Position-based insertion & deletion
* Circular and linear list handling
* Object-oriented design
* Reusable and extensible structure

---

## 🛠️ Technologies Used

* **Language:** C++
* **Concepts:**

  * Templates (Generic Programming)
  * Object-Oriented Programming (OOP)
  * Dynamic Memory Management
  * Data Structures

---

## 📂 Project Structure

```id="s5j9eo"
DSA-Generic-Library/
│
├── main.cpp
└── README.md
```

---

## ▶️ How to Run

### Compile

```bash id="nbphqz"
g++ main.cpp -o myexe
```

### Execute

```bash id="fyv1at"
./myexe
```

---

## 💻 Example Usage

```cpp id="nl6rb4"
SinglyLLL<int> obj;
obj.InsertFirst(10);
obj.InsertLast(20);
obj.Display();
```

---

## 📚 Learning Outcomes

* Deep understanding of linked list variations
* Practical implementation of Stack & Queue
* Hands-on experience with generic programming
* Strong foundation in data structures

---

## 👨‍💻 Author

**Aditya Dipak Shejwal**

---

## ⭐ Future Improvements

* Separate header files for each structure
* Exception handling
* STL-like interface design
* Iterator support

---
