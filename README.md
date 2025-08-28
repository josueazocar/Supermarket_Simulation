<img width="620" height="464" alt="image" src="https://github.com/user-attachments/assets/cb02fd68-3264-4a20-9094-1f28c36d37f6" />
<img width="1080" height="600" alt="image" src="https://github.com/user-attachments/assets/b6e3dc5b-2ae1-47a0-a159-ab3a5fa5fe33" />
<img width="1080" height="500" alt="image" src="https://github.com/user-attachments/assets/355502bd-78cc-4168-97d2-b10c4a61eb1f" />

## Project Description

This project focuses on the emulation of an **automated shopping management system**. Its main objective is to simulate a customer's interaction with a virtual shopping cart that operates under crucial constraints of **time, stock, and capacity**.

The system was designed to be robust and realistic, integrating complex business logic with an intuitive user interface.

## Technologies and Development Environment

- **Programming Language:** C++
- **Integrated Development Environment (IDE):** Visual Studio
- **Graphical User Interface (GUI):** WinForms

## Key Technical Challenges and Features

During the project's development, several significant technical challenges were addressed to ensure an accurate system simulation:

### 1. Shopping Cart Management
**Stacks** were implemented to manage the virtual cart. The system is designed with strict limits:
- A maximum of 10 items per stack.
- A total limit of 30 items per purchase.

### 2. Customer Queue Simulation
To emulate customer waiting in a store, **queues** were used. This feature allows for the simulation of a waiting line with customizable times, adding a component of realism to the system.

### 3. Process Synchronization
Synchronization logic was implemented to ensure that each purchase does not exceed a time limit. This limit, which defaults to 10 minutes, is fully **customizable** and can be adjusted according to the system's needs.

