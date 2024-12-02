CREATE DATABASE AutoDealer;

USE AutoDealer;

CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Position ENUM('Manager', 'Salesman') NOT NULL,
    Salary DECIMAL(10, 2),
    CommissionRate DECIMAL(5, 2),
    HireDate DATE
);

CREATE TABLE Customer (
    CustomerID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    ContactInfo VARCHAR(100),
    CustomerType ENUM('Leasing', 'Buying') NOT NULL
);

CREATE TABLE Inventory (
    VehicleID INT PRIMARY KEY,
    Make VARCHAR(50),
    Model VARCHAR(50),
    VehicleYear INT,
    VIN VARCHAR(50) UNIQUE,
    Price DECIMAL(10, 2),
    VehicleCondition ENUM('New', 'Used') NOT NULL,
    Color VARCHAR(50)
);

CREATE TABLE Sales (
    SaleID INT PRIMARY KEY,
    SaleDate DATE NOT NULL,
    TotalAmount DECIMAL(10, 2) NOT NULL,
    PaymentMethod ENUM('Cash', 'Credit', 'Financing') NOT NULL,
    SalesmanID INT,
    CustomerID INT,
    VehicleID INT,
    FOREIGN KEY (SalesmanID) REFERENCES Employee(EmployeeID),
    FOREIGN KEY (CustomerID) REFERENCES Customer(CustomerID),
    FOREIGN KEY (VehicleID) REFERENCES Inventory(VehicleID)
);

CREATE TABLE Commission  
 (
    CommissionID INT PRIMARY KEY,
    EmployeeID INT,
    SaleID INT,
    CommissionAmount DECIMAL(10, 2),
    FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID),
    FOREIGN KEY (SaleID) REFERENCES Sales(SaleID)
);

CREATE TABLE Financing (
    FinanceID INT PRIMARY KEY,
    CustomerID INT,
    VehicleID INT,
    LoanAmount DECIMAL(10, 2),
    InterestRate DECIMAL(5, 2),
    MonthlyPayment DECIMAL(10, 2),
    RemainingPayments INT,
    ApprovalStatus ENUM('Approved', 'Pending', 'Rejected'),
    FOREIGN KEY (CustomerID) REFERENCES Customer(CustomerID),
    FOREIGN KEY (VehicleID) REFERENCES Inventory(VehicleID)
);

CREATE TABLE Lease (
    LeaseID INT PRIMARY KEY,
    CustomerID INT,
    VehicleID INT,
    MonthlyPayment DECIMAL(10, 2),
    RemainingPayments INT,
    LeaseTerm INT,
    LeaseStartDate DATE,
    LeaseEndDate DATE,
    FOREIGN KEY (CustomerID) REFERENCES Customer(CustomerID),
    FOREIGN KEY (VehicleID) REFERENCES Inventory(VehicleID)
);

CREATE TABLE Service (
    ServiceID INT PRIMARY KEY,
    VehicleID INT,
    ServiceType VARCHAR(100),
    ServiceDate DATE,
    RepairPerformed VARCHAR(255),
    ServiceCost DECIMAL(10, 2),
    FOREIGN KEY (VehicleID) REFERENCES Inventory(VehicleID)
);

CREATE TABLE DealerFinancialData (
    FinancialDataID INT PRIMARY KEY,
    EmployeeID INT,
    DateYear INT,
    DateMonth INT,
    TotalSalesRevenue DECIMAL(10, 2),
    TotalServiceRevenue DECIMAL(10, 2),
    TotalOperatingExpenses DECIMAL(10, 2),
    NetProfit DECIMAL(10, 2),
    FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID)
);


INSERT INTO Employee VALUES (1, 'John', 'Doe', 'Manager', 60000.00, 0.00, '2024-11-22');
INSERT INTO Employee VALUES (2, 'Jane', 'Smith', 'Salesman', 40000.00, 0.10, '2024-09-21');
INSERT INTO Employee VALUES (3, 'Mike', 'Johnson', 'Salesman', 50000.00, 0.15, '2024-10-14');

INSERT INTO Customer VALUES (1, 'Alice', 'Brown', '123 Main St, Houston, TX 77001', 'Leasing');
INSERT INTO Customer VALUES (2, 'Bob', 'White', '456 Elm St, Houston, TX 77002', 'Buying');
INSERT INTO Customer VALUES (3, 'Charlie', 'Green', '789 Oak St, Houston, TX 77003', 'Leasing');

INSERT INTO Inventory VALUES (1, 'Toyota', 'Camry', 2023, '123456789', 25000.00, 'New', 'Red');
INSERT INTO Inventory VALUES (2, 'Honda', 'Accord', 2022, '987654321', 30000.00, 'New', 'Blue');
INSERT INTO Inventory VALUES (3, 'Ford', 'F-150', 2008, '456789123', 10000.00, 'Used', 'Black');
INSERT INTO Inventory VALUES (4, 'Chevrolet', 'Silverado', 2015, '654321987', 20000.00, 'Used', 'White');

INSERT INTO Sales VALUES (1, '2024-01-20', 36000.00, 'Cash', 2, 1, 1);
INSERT INTO Sales VALUES (2, '2024-01-21', 20000.00, 'Credit', 3, 2, 2);
INSERT INTO Sales VALUES (3, '2024-01-22', 10000.00, 'Financing', 3, 3, 3);

INSERT INTO Commission VALUES (1, 2, 1, 2500.00);
INSERT INTO Commission VALUES (2, 3, 2, 4000.00);
INSERT INTO Commission VALUES (3, 3, 3, 3000.00);

INSERT INTO Financing VALUES (1, 2, 2, 30000.00, 0.06, 700.00, 50, 'Approved');
INSERT INTO Financing VALUES (2, 3, 1, 25000.00, 0.05, 500.00, 60, 'Approved');

INSERT INTO Lease VALUES (1, 1, 3, 300.00, 36, 3, '2024-01-20', '2027-01-20');
INSERT INTO Lease VALUES (2, 3, 1, 250.00, 36, 3, '2024-01-20', '2027-01-20');

INSERT INTO Service VALUES (1, 1, 'Oil Change', '2024-01-20', 'Performed oil change service', 50.00);
INSERT INTO Service VALUES (2, 2, 'Tire Rotation', '2024-01-21', 'Performed tire rotation service', 100.00);

INSERT INTO DealerFinancialData VALUES (1, 1, 2024, 1, 55000.00, 150.00, 50000.00, 5000.00);
INSERT INTO DealerFinancialData VALUES (2, 1, 2024, 2, 60000.00, 200.00, 55000.00, 6000.00);

--First Join Query
SELECT 
    e.EmployeeID,
    e.FirstName,
    e.LastName,
    s.SaleID,
    s.SaleDate
FROM 
    Employee e
INNER JOIN 
    Sales s ON e.EmployeeID = s.SalesmanID;

--Second Join Query
SELECT 
    c.CustomerID,
    c.FirstName,
    c.LastName,
    s.SaleID,
    v.Make,
    v.Model
FROM 
    Customer c
INNER JOIN 
    Sales s ON c.CustomerID = s.CustomerID
INNER JOIN 
    Inventory v ON s.VehicleID = v.VehicleID;

--Aggregate Queries for Each Table:
--Employee Table
SELECT 
    Position, 
    COUNT(*) AS TotalEmployees, 
    AVG(Salary) AS AverageSalary
FROM Employee
GROUP BY Position;

--Customer Table
SELECT 
    CustomerType, 
    COUNT(*) AS TotalCustomers
FROM Customer
GROUP BY CustomerType;

--Inventory Table
SELECT 
    VehicleCondition, 
    COUNT(*) AS TotalVehicles, 
    AVG(Price) AS AveragePrice
FROM Inventory
GROUP BY VehicleCondition;

--Sales Table
SELECT 
    PaymentMethod, 
    COUNT(*) AS TotalSales, 
    SUM(TotalAmount) AS TotalRevenue
FROM Sales
GROUP BY PaymentMethod;

--Commission Table
SELECT 
    EmployeeID, 
    COUNT(*) AS TotalCommissions, 
    SUM(CommissionAmount) AS TotalCommission
FROM Commission
GROUP BY EmployeeID;

--Financing Table
SELECT 
    ApprovalStatus, 
    COUNT(*) AS TotalFinancing
FROM Financing
GROUP BY ApprovalStatus;

--Lease Table
SELECT 
    COUNT(*) AS TotalLeases
FROM Lease
GROUP BY LeaseTerm;

--Service Table
SELECT 
    ServiceType, 
    COUNT(*) AS TotalServices, 
    SUM(ServiceCost) AS TotalServiceCost
FROM Service
GROUP BY ServiceType;

--DealerFinancialData Table
SELECT 
    DateYear, 
    DateMonth, 
    SUM(TotalSalesRevenue) AS TotalSalesRevenue, 
    SUM(TotalServiceRevenue) AS TotalServiceRevenue, 
    SUM(TotalOperatingExpenses) AS TotalOperatingExpenses, 
    SUM(NetProfit) AS NetProfit
FROM DealerFinancialData
GROUP BY DateYear, DateMonth;

--Joint Queries for Directly Related Tables:
--Employee and Sales Tables
SELECT 
    e.EmployeeID, 
    e.FirstName, 
    e.LastName,
    COUNT(s.SaleID) AS TotalSales, 
    SUM(s.TotalAmount) AS TotalSalesAmount
FROM Employee e
JOIN Sales s ON e.EmployeeID = s.SalesmanID
GROUP BY e.EmployeeID;

--Customer and Sales Tables
SELECT 
    s.SaleID, 
    s.SaleDate, 
    c.FirstName AS CustomerFirst, 
    c.LastName AS CustomerLast, 
    s.TotalAmount 
FROM Sales s
JOIN Customer c ON s.CustomerID = c.CustomerID;

--Sales and Inventory Tables
SELECT 
    s.SaleID, 
    i.Make, 
    i.Model, 
    s.TotalAmount
FROM Sales s
JOIN Inventory i ON s.VehicleID = i.VehicleID;

--Employee and Commission Tables
SELECT 
    e.EmployeeID, 
    e.FirstName, 
    e.LastName, 
    SUM(c.CommissionAmount) AS TotalCommission
FROM Employee e
JOIN Commission c ON e.EmployeeID = c.EmployeeID
GROUP BY e.EmployeeID;

--Customer and Financing Tables
SELECT 
    c.FirstName, 
    c.LastName, 
    f.LoanAmount, 
    f.InterestRate, 
    f.MonthlyPayment, 
    f.ApprovalStatus
FROM Customer c
JOIN Financing f ON c.CustomerID = f.CustomerID;

--Customer and Lease Tables
SELECT 
    c.FirstName, 
    c.LastName, 
    l.MonthlyPayment, 
    l.LeaseStartDate, 
    l.LeaseEndDate 
FROM Customer c
JOIN Lease l ON c.CustomerID = l.CustomerID;

--Inventory and Service Tables
SELECT 
    i.Make, 
    i.Model, 
    s.ServiceType, 
    s.ServiceDate, 
    s.ServiceCost 
FROM Inventory i
JOIN Service s ON i.VehicleID = s.VehicleID;

--Employee and DealerFinancialData Tables
SELECT 
    e.FirstName, 
    e.LastName, 
    d.DateYear, 
    d.TotalSalesRevenue, 
    d.TotalServiceRevenue, 
    d.NetProfit
FROM Employee e
JOIN DealerFinancialData d ON e.EmployeeID = d.EmployeeID;

--Sales and Commission Tables
SELECT 
    s.SaleID, 
    s.SaleDate, 
    c.CommissionAmount
FROM Sales s
JOIN Commission c ON s.SaleID = c.SaleID;

--Sales and Financing Tables
SELECT 
    s.SaleID, 
    f.LoanAmount, 
    f.InterestRate, 
    f.MonthlyPayment, 
    f.ApprovalStatus
FROM Sales s
JOIN Financing f ON s.CustomerID = f.CustomerID;

--Sales and Lease Tables
SELECT 
    s.SaleID, 
    l.MonthlyPayment, 
    l.LeaseTerm, 
    l.LeaseStartDate, 
    l.LeaseEndDate
FROM Sales s
JOIN Lease l ON s.CustomerID = l.CustomerID;
