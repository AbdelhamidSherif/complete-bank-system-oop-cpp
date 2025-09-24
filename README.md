# Complete Bank Management System - OOP Edition

A comprehensive C++ Object-Oriented Banking System featuring advanced client management, secure user authentication, transaction processing, currency exchange, and complete audit trails.

## 🏦 Overview

This Complete Bank Management System represents the culmination of a comprehensive banking software series, built using **Object-Oriented Programming (OOP)** principles. This enterprise-level system provides full banking operations with advanced security features, multi-user support, currency exchange capabilities, and detailed audit logging.

### 🎯 Programming Paradigm Evolution

This system demonstrates the evolution from **Functional Programming** to **Object-Oriented Programming**, featuring:
- **Class-based architecture** with proper encapsulation and inheritance
- **Polymorphism** for flexible operation handling
- **Design patterns** implementation (Factory, Strategy, Template Method)
- **SOLID principles** adherence throughout the codebase
- **Advanced OOP concepts** including operator overloading and properties

### 🔄 Project Series Comparison

This OOP version represents the most advanced implementation in the banking system series:

| Feature | Functional Versions | OOP Version (Current) |
|---------|--------------------|-----------------------|
| **Architecture** | Function-based | Class-based with inheritance |
| **Code Organization** | Modular functions | Organized class hierarchy |
| **Data Management** | Structs + functions | Encapsulated classes |
| **User System** | Basic permissions | Advanced role-based access |
| **Currency Support** | None | Complete currency exchange |
| **Audit Trail** | Basic logging | Comprehensive audit system |
| **Security** | File-based | Encrypted passwords + sessions |
| **Extensibility** | Limited | Highly extensible through OOP |

## 🏗️ System Architecture

### Three-Tier Architecture Implementation

This system follows a **Three-Tier Architecture** pattern, providing clear separation of concerns:

#### 1. Presentation Tier (UI Layer)
**Location**: `Screens/` directory
- **Purpose**: Handles all user interactions and display logic
- **Components**:
  - `clsScreen.h` - Base screen class with common UI functionality
  - Client Management Screens (Add, Delete, Update, List, Find)
  - Transaction Screens (Deposit, Withdraw, Transfer)
  - User Management Screens (User CRUD operations)
  - Currency Exchange Screens (List, Calculator, Rate Update)
  - Authentication Screens (Login, Register)
- **Responsibilities**: Input validation, output formatting, menu navigation, user prompts

#### 2. Business Logic Tier (Application Layer)
**Location**: `Core/` directory
- **Purpose**: Contains all business rules and application logic
- **Components**:
  - `clsBankClient.h` - Client business logic and operations
  - `clsUser.h` - User management and authentication logic  
  - `clsCurrency.h` - Currency exchange business rules
  - Permission validation and security enforcement
  - Transaction processing and validation rules
- **Responsibilities**: Business rule enforcement, data validation, security checks, calculations

#### 3. Data Access Tier (Data Layer)
**Location**: File-based storage system
- **Purpose**: Handles all data storage and retrieval operations
- **Components**:
  - File I/O operations (Read/Write/Update/Delete)
  - Data serialization/deserialization
  - Data format conversion (Object ↔ File format)
  - Data integrity maintenance
- **Data Files**:
  - `Clients.txt` - Client account data
  - `Users.txt` - User accounts and permissions
  - `Currencies.txt` - Exchange rates database
  - `TransferLog.txt` - Transaction audit trail
  - `LoginRegister.txt` - User session logs

### Architecture Benefits

**Separation of Concerns**: Each tier has distinct responsibilities
- UI changes don't affect business logic
- Business rules are independent of data storage
- Data format changes don't impact user interface

**Maintainability**: Easy to modify individual layers
- Update UI without touching business logic
- Change business rules without affecting data layer
- Switch from file-based to database storage easily

**Scalability**: Each tier can be optimized independently
- UI can be replaced with web/mobile interface
- Business logic can be moved to separate server
- Data layer can migrate to enterprise database

**Testability**: Each tier can be tested in isolation
- Unit tests for business logic
- UI tests for user interaction
- Data layer tests for storage operations

### OOP Implementation in Three-Tier Architecture

#### Presentation Tier Classes
```cpp
clsScreen (Base Class)
├── Client Management
│   ├── clsClientListScreen : protected clsScreen
│   ├── clsAddNewClientScreen : protected clsScreen
│   └── clsDeleteClientScreen : protected clsScreen
├── Transaction Management  
│   ├── clsTransactionsScreen : protected clsScreen
│   └── clsDepositScreen : protected clsScreen
└── User Management
    ├── clsManageUsersScreen : protected clsScreen
    └── clsAddNewUserScreen : protected clsScreen
```

#### Business Logic Tier Classes
```cpp
clsPerson (Base Entity)
├── clsBankClient : public clsPerson (Client Business Logic)
└── clsUser : public clsPerson (User Business Logic)

clsCurrency (Currency Business Logic)
├── Exchange rate calculations
├── Currency conversion logic
└── Multi-currency support
```

#### Data Access Tier Integration
```cpp
// Encapsulated within business logic classes
private:
    static vector<clsBankClient> _LoadClientsDataFromFile()
    static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
    static clsBankClient _ConvertLineToClientObject(string Line)
    static string _ConvertClientObjectToLine(clsBankClient Client)
```

## ✨ Comprehensive Features

### 👥 Advanced Client Management
- **Complete CRUD Operations**: Create, read, update, delete clients
- **Inheritance-based Design**: Clients inherit from Person class
- **Data Encapsulation**: Private members with property accessors
- **Polymorphic Operations**: Virtual functions for extensibility
- **Advanced Search**: Multiple search criteria and filters

### 🔐 Enterprise Security System
- **Multi-level Authentication**: Username/password with session management
- **Granular Permissions**: 9 different permission levels (256 combinations)
- **Password Encryption**: Built-in encryption/decryption system
- **Session Tracking**: Complete login/logout audit trail
- **Access Control**: Method-level permission checking

### 💰 Comprehensive Transaction System
- **Deposit/Withdrawal Operations**: Full balance management
- **Inter-account Transfers**: Secure money transfers between accounts
- **Transaction Logging**: Complete audit trail for all transactions
- **Balance Reporting**: System-wide balance calculations
- **Transaction Validation**: Multi-layer validation system

### 💱 Currency Exchange Module
- **Multi-currency Support**: 150+ world currencies
- **Real-time Rate Management**: Update exchange rates
- **Currency Calculator**: Convert between any currencies
- **USD Base System**: All conversions through USD standard
- **Rate History**: Track currency rate changes

### 📊 Advanced Reporting & Audit
- **Login Register**: Complete user session history
- **Transfer Log**: Detailed transaction audit trail
- **Balance Reports**: Comprehensive financial reporting
- **User Activity**: Track all user actions
- **System Analytics**: Usage statistics and trends

## 🗂️ File Organization

```
Complete-Bank-System-OOP/
├── Core/
│   ├── clsBankClient.h        # Main client class with business logic
│   ├── clsCurrency.h          # Currency management class
│   ├── clsPerson.h           # Base person class
│   └── clsUser.h             # User management with permissions
├── Lib/
│   ├── clsDate.h             # Advanced date manipulation
│   ├── clsInputValidate.h    # Input validation utilities
│   ├── clsString.h           # String manipulation class
│   └── clsUtil.h             # General utility functions
├── Screens/
│   ├── Client/
│   │   ├── clsAddNewClientScreen.h
│   │   ├── clsClientListScreen.h
│   │   ├── clsDeleteClientScreen.h
│   │   ├── clsDepositScreen.h
│   │   ├── clsFindClientScreen.h
│   │   ├── clsTotalBalanceScreen.h
│   │   ├── clsTransactionsScreen.h
│   │   ├── clsTransferLogScreen.h
│   │   ├── clsTransferScreen.h
│   │   ├── clsUpdateClientScreen.h
│   │   └── clsWithdrawScreen.h
│   ├── Currencies/
│   │   ├── clsCurrenciesListScreen.h
│   │   ├── clsCurrencyCalculatorScreen.h
│   │   ├── clsCurrencyExchangeMainScreen.h
│   │   ├── clsFindCurrencyScreen.h
│   │   └── clsUpdateCurrencyRateScreen.h
│   ├── User/
│   │   ├── clsAddNewUserScreen.h
│   │   ├── clsDeleteUserScreen.h
│   │   ├── clsFindUserScreen.h
│   │   ├── clsLoginRegisterScreen.h
│   │   ├── clsLoginScreen.h
│   │   ├── clsManageUsersScreen.h
│   │   ├── clsUpdateUserScreen.h
│   │   └── clsUsersListScreen.h
│   ├── clsMainScreen.h
│   └── clsScreen.h           # Base screen class
├── Global.h                   # Global variables and declarations
├── resource.h                 # Resource definitions
├── Bank_System.cpp           # Main application entry point
└── Bank_System.rc            # Resource file
```

## 🚀 Getting Started

### Prerequisites
- C++ compiler with C++11 support (Visual Studio, GCC, or Clang)
- Windows OS (for resource files and system calls)
- Standard C++ libraries

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/AbdelhamidSherif/complete-bank-system-oop.git
   cd complete-bank-system-oop
   ```

2. **Compile the project**
   ```bash
   # Using Visual Studio
   Open Bank_System.sln and build

   # Using GCC
   g++ -std=c++11 -o BankSystem Bank_System.cpp
   ```

3. **Setup initial data files**
   The system will create necessary data files:
   - `Clients.txt` - Client database
   - `Users.txt` - User accounts database  
   - `Currencies.txt` - Currency exchange rates
   - `TransferLog.txt` - Transaction audit trail
   - `LoginRegister.txt` - User session logs

4. **Run the application**
   ```bash
   ./BankSystem
   ```

## 📋 Usage Guide

### Initial System Login

Use this sample admin account to access the system:

**System Administrator:**
- Username: `Admin`
- Password: `0000`
- Permissions: Full system access

*Note: The system uses password encryption - actual stored passwords are encrypted using a custom encryption algorithm implemented in clsUtil class.*

### Main System Menu
1. **Show Client List** - View all bank clients
2. **Add New Client** - Register new customers
3. **Delete Client** - Remove client accounts
4. **Update Client Info** - Modify client details
5. **Find Client** - Search for specific clients
6. **Transactions** - Access transaction management
7. **Manage Users** - User account administration
8. **Login Register** - View user session history
9. **Currency Exchange** - Currency management system
10. **Logout** - End current session

### Permission System
The system supports 9 permission levels:
- **List Clients** (1): View client information
- **Add New Client** (2): Create new accounts
- **Delete Client** (4): Remove client accounts
- **Update Clients** (8): Modify client information
- **Find Client** (16): Search capabilities
- **Transactions** (32): Financial operations
- **Manage Users** (64): User administration
- **Login Register** (128): Audit trail access
- **Currency Exchange** (256): Currency operations

Permissions can be combined (e.g., 51 = List + Add + Find + Transactions)

## 🔧 Advanced Features

### Object-Oriented Design Patterns

#### 1. Template Method Pattern
Used in screen base classes for consistent UI flow

#### 2. Factory Pattern
User and client object creation with different modes

#### 3. Strategy Pattern
Different validation strategies for various input types

#### 4. Observer Pattern
Event handling for transactions and user actions

### Encapsulation Examples
```cpp
class clsBankClient : public clsPerson {
private:
    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;
    
public:
    // Property-style accessors
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;
};
```

### Inheritance Hierarchy
```cpp
clsPerson
├── Shared properties: FirstName, LastName, Email, Phone
├── clsBankClient: Adds banking-specific features
└── clsUser: Adds authentication and permissions
```

## 💾 Data Management

### File-based Persistence
- **Structured Data Format**: Delimited text files for cross-platform compatibility
- **Data Integrity**: Built-in validation and error checking
- **Backup Support**: Easy data backup and restore
- **Encryption**: Password encryption for security

### Data Structures
```cpp
// Client record format
FirstName#//#LastName#//#Email#//#Phone#//#AccountNumber#//#PinCode#//#Balance

// User record format  
FirstName#//#LastName#//#Email#//#Phone#//#Username#//#EncryptedPassword#//#Permissions

// Currency record format
Country#//#CurrencyCode#//#CurrencyName#//#ExchangeRate
```

## 🔒 Security Features

### Authentication Security
- **Encrypted password storage** using custom encryption
- **Session management** with user context tracking
- **Failed login tracking** with account lockout protection
- **Permission-based access control** at method level

### Data Protection
- **Input validation** throughout the system
- **SQL injection protection** (file-based, but prepared for DB)
- **Buffer overflow protection** with proper string handling
- **Audit logging** for all critical operations

## 📈 System Usage Analytics

Based on the login register data, the system shows active usage with:
- **80+ login sessions** recorded
- **Multiple user types** actively using different permission levels
- **Real transaction history** with $6,700 total transferred between accounts
- **Active currency management** with 150+ supported currencies
- **Regular audit trail maintenance** showing system reliability

## 🛠️ Future Enhancements

### Technical Improvements
- [ ] Database integration (MySQL/PostgreSQL/SQLite)
- [ ] Web-based interface with REST API
- [ ] Mobile app integration
- [ ] Real-time notifications system
- [ ] Advanced reporting with charts
- [ ] Data analytics and insights
- [ ] Cloud deployment support
- [ ] Multi-language support

### Banking Features
- [ ] Loan management system
- [ ] Investment portfolio tracking
- [ ] Credit card management
- [ ] Bill payment integration
- [ ] Mobile check deposit
- [ ] ATM network integration
- [ ] International wire transfers
- [ ] Cryptocurrency support

### Security Enhancements
- [ ] Two-factor authentication
- [ ] Biometric authentication
- [ ] Advanced fraud detection
- [ ] Real-time security monitoring
- [ ] Compliance reporting (SOX, PCI DSS)
- [ ] End-to-end encryption
- [ ] Security incident response
- [ ] Penetration testing integration

## 🔗 Related Projects

This project represents the culmination of a complete banking system series:

### 📂 **Complete Project Series:**
1. **[Basic Bank Management](https://github.com/AbdelhamidSherif/bank-management-functional-cpp)** - Functional programming with basic CRUD
2. **[Enhanced Bank System](https://github.com/AbdelhamidSherif/enhanced-bank-system-functional)** - Added transaction management
3. **[Secure Bank System](https://github.com/AbdelhamidSherif/secure-bank-system-functional)** - Multi-user security system
4. **[ATM System](https://github.com/AbdelhamidSherif/atm-banking-system-cpp)** - Customer-facing ATM interface
5. **Current Project** - Complete OOP enterprise banking solution

### 🔄 **Quick Navigation:**
- [View Functional Series →](https://github.com/AbdelhamidSherif?tab=repositories&q=functional&type=&language=) - See the evolution from functional programming
- [View ATM System →](https://github.com/AbdelhamidSherif/atm-banking-system-cpp) - Customer interface perspective
- [See All Banking Projects →](https://github.com/AbdelhamidSherif?tab=repositories&q=bank&type=&language=) - Complete ecosystem

## 📊 Project Statistics

- **Total Classes**: 50+ classes
- **Lines of Code**: 3000+ lines
- **Header Files**: 40+ files
- **Features**: 25+ major features
- **Screens**: 20+ user interfaces
- **Security Levels**: 9 permission types
- **Currency Support**: 150+ currencies
- **File Types**: 5 different data files

## 🤝 Contributing

This project demonstrates advanced OOP concepts and enterprise-level architecture. Contributions are welcome!

### Contribution Guidelines
- Follow OOP best practices
- Maintain existing code style
- Add comprehensive documentation
- Include unit tests for new features
- Update relevant README sections

### Areas for Contribution
- Additional banking features
- Performance optimizations
- Security enhancements
- UI/UX improvements
- Database integration
- API development
- Testing framework

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

**Abdelhamid Sherif**
- GitHub: [@AbdelhamidSherif](https://github.com/AbdelhamidSherif)
- LinkedIn: [Abdelhamid Sherif](https://linkedin.com/in/abdelhamid-sherif)
- Email: abdelhamidsherif.engineer.career@gmail.com

## 🙏 Acknowledgments

- Inspired by real-world enterprise banking systems
- Demonstrates practical application of OOP principles in C++
- Educational project showcasing software architecture evolution
- Thanks to all contributors and the C++ community

## 📞 Support

For questions, bug reports, or feature requests:
1. Check existing issues in the repository
2. Create a new issue with detailed description
3. Join our discussions in the repository
4. Contact the maintainer directly

---

⭐ If you found this project valuable for learning OOP concepts and enterprise software architecture, please give it a star on GitHub!
