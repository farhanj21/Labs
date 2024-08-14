CREATE DATABASE ORDERS1
use ORDERS1

CREATE TABLE Customers (
  CustomerNo VARCHAR(10) PRIMARY KEY,
  Name VARCHAR(50),
  City VARCHAR(50),
  Phone VARCHAR(20)
);

CREATE TABLE Orders (
  OrderNo INT PRIMARY KEY,
  CustomerNo VARCHAR(10),
  Date DATE,
  Total_Items_Ordered INT,
  FOREIGN KEY (CustomerNo) REFERENCES Customers(CustomerNo)
);


CREATE TABLE Items (
  ItemNo VARCHAR(10) PRIMARY KEY,
  Name VARCHAR(50),
  Price INT,
  Quantity_in_store INT
);

CREATE TABLE Order_Details (
  OrderNo INT,
  ItemNo VARCHAR(10),
  Quantity INT,
  PRIMARY KEY (OrderNo, ItemNo),
  FOREIGN KEY (OrderNo) REFERENCES Orders(OrderNo),
  FOREIGN KEY (ItemNo) REFERENCES Items(ItemNo)
);

INSERT INTO Customers (CustomerNo, Name, City, Phone) VALUES 
('C1', 'AHMED ALI', 'LHR', '111111'),
('C2', 'ALI', 'LHR', '222222'),
('C3', 'AYESHA', 'LHR', '333333'),
('C4', 'BILAL', 'KHI', '444444'),
('C5', 'SADAF', 'KHI', '555555'),
('C6', 'FARAH', 'ISL', '666666');

INSERT INTO Orders (OrderNo, CustomerNo, Date, Total_Items_Ordered) VALUES 
(1, 'C1', '2012-12-11', 30),
(2, 'C2', '2016-12-01', 5),
(3, 'C3', '2017-01-01', 20),
(4, 'C4', '2017-01-02', 15);


INSERT INTO Items (ItemNo, Name, Price, Quantity_in_store) VALUES 
('100', 'A', 1000, 100),
('200', 'B', 2000, 50),
('300', 'C', 3000, 60),
('400', 'D', 6000, 40);

INSERT INTO Order_Details (OrderNo, ItemNo, Quantity) VALUES 
(1, '200', 20),
(1, '400', 10),
(2, '200', 5),
(3, '200', 60);

--Query 1
CREATE TRIGGER PreventCustomerDelete
ON Customers
INSTEAD OF DELETE
AS
BEGIN
  IF EXISTS (SELECT 1 FROM Orders WHERE CustomerNo IN (SELECT CustomerNo FROM deleted))
  BEGIN
    PRINT 'Cannot delete customer(s) with orders.';
  END
  ELSE
  BEGIN
    DELETE FROM Customers WHERE CustomerNo IN (SELECT CustomerNo FROM deleted);
  END
END;

--Query 2
CREATE TRIGGER CheckQuantityAvailability
ON Order_Details
INSTEAD OF INSERT
AS
BEGIN
  DECLARE @ItemNo VARCHAR(10), @Quantity INT, @QuantityInStore INT;
  SELECT @ItemNo = ItemNo, @Quantity = Quantity FROM inserted;
  
  SELECT @QuantityInStore = Quantity_in_store FROM Items WHERE ItemNo = @ItemNo;
  
  IF @Quantity <= @QuantityInStore
  BEGIN
    INSERT INTO Order_Details (OrderNo, ItemNo, Quantity) SELECT OrderNo, ItemNo, Quantity FROM inserted;
  END
  ELSE
  BEGIN
    PRINT 'The required quantity is not available.';
  END
END;

--Query 3
CREATE TRIGGER CheckQuantityUpdate
ON Order_Details
AFTER UPDATE
AS
BEGIN
  DECLARE @ItemNo VARCHAR(10), @Quantity INT, @QuantityInStore INT;
  SELECT @ItemNo = ItemNo, @Quantity = Quantity FROM inserted;
  
  SELECT @QuantityInStore = Quantity_in_store FROM Items WHERE ItemNo = @ItemNo;
  
  IF @Quantity > @QuantityInStore
  BEGIN
    PRINT 'Rolling back update. The required quantity is not available in the store.';
    ROLLBACK;
  END
END;

--Query 4
CREATE TRIGGER PreventDeleteItem
ON Items
AFTER DELETE
AS
BEGIN
  IF EXISTS (SELECT 1 FROM Items WHERE Quantity_in_store > 100)
  BEGIN
    PRINT 'Cannot delete items with quantity in store greater than 100.';
    ROLLBACK;
  END
END;

--Query 5
CREATE TRIGGER SetCurrentDate
ON Orders
INSTEAD OF INSERT
AS
BEGIN
  INSERT INTO Orders (OrderNo, CustomerNo, Date, Total_Items_Ordered)
  SELECT OrderNo, CustomerNo, GETDATE(), Total_Items_Ordered FROM inserted;
END;

--Query 6
CREATE TRIGGER PreventInsertCustomer
ON Customers
AFTER INSERT
AS
BEGIN
  IF EXISTS (SELECT 1 FROM inserted WHERE CustomerNo IS NULL OR Name IS NULL OR City IS NULL OR Phone IS NULL)
  BEGIN
    PRINT 'Cannot insert customer with null fields.';
    ROLLBACK;
  END
END;

--Query 7
CREATE PROCEDURE CustomerSignup
    @CustomerNo VARCHAR(10),
    @Name VARCHAR(50),
    @City VARCHAR(50),
    @Phone VARCHAR(20),
    @Flag INT OUTPUT
AS
BEGIN
    SET NOCOUNT ON;

    IF EXISTS (SELECT 1 FROM Customers WHERE CustomerNo = @CustomerNo)
    BEGIN
        SET @Flag = 1;
        RETURN;
    END

    IF LEN(@Phone) <> 6
    BEGIN
        SET @Flag = 3;
        RETURN;
    END

    INSERT INTO Customers (CustomerNo, Name, City, Phone) VALUES (@CustomerNo, @Name, @City, @Phone);
    SET @Flag = 0;
END
DECLARE @Flag INT;
EXEC spCustomerSignup 'C7', 'SARA', 'LHR', '123456', @Flag OUTPUT;
SELECT @Flag;


