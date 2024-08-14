Create database ATM
go 
use ATM
go

create table [User](
[userId] int primary key,
[name] varchar(20) not null,
[phoneNum] varchar(15) not null,
[city] varchar(20) not null
)
go

create table CardType(
[cardTypeID] int primary key,
[name] varchar(15),
[description] varchar(40) null
)
go
create Table [Card](
cardNum Varchar(20) primary key,
cardTypeID int foreign key references  CardType([cardTypeID]),
PIN varchar(4) not null,
[expireDate] date not null,
balance float not null
)
go


Create table UserCard(
userID int foreign key references [User]([userId]),
cardNum varchar(20) foreign key references [Card](cardNum),
primary key(cardNum)
)
go
create table [Transaction](
transId int primary key,
transDate date not null,
cardNum varchar(20) foreign key references [Card](cardNum),
amount int not null
)


INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (1, N'Ali', N'03036067000', N'Narowal')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (2, N'Ahmed', N'03036047000', N'Lahore')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (3, N'Aqeel', N'03036063000', N'Karachi')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (4, N'Usman', N'03036062000', N'Sialkot')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (5, N'Hafeez', N'03036061000', N'Lahore')
GO


INSERT [dbo].[CardType] ([cardTypeID], [name], [description]) VALUES (1, N'Debit', N'Spend Now, Pay Now')
GO
INSERT [dbo].[CardType] ([cardTypeID], [name], [description]) VALUES (2, N'Credit', N'Spend Now, Pay later')
GO

INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1234', 1, N'1770', CAST(N'2022-07-01' AS Date), 43025.31)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1235', 1, N'9234', CAST(N'2020-03-02' AS Date), 14425.62)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1236', 1, N'1234', CAST(N'2019-02-06' AS Date), 34325.52)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1237', 2, N'1200', CAST(N'2021-02-05' AS Date), 24325.3)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1238', 2, N'9004', CAST(N'2020-09-02' AS Date), 34025.12)
GO

INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (1, N'1234')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (1, N'1235')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (2, N'1236')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (3, N'1238')
GO
Insert  [dbo].[UserCard] ([userID], [cardNum]) VALUES (4, N'1237')

INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (1, CAST(N'2017-02-02' AS Date), N'1234', 500)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (2, CAST(N'2018-02-03' AS Date), N'1235', 3000)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (3, CAST(N'2020-01-06' AS Date), N'1236', 2500)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (4, CAST(N'2016-09-09' AS Date), N'1238', 2000)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (5, CAST(N'2020-02-10' AS Date), N'1234', 6000)
GO

Select * from [User]
Select * from UserCard
Select * from [Card]
Select * from CardType
Select * from [Transaction]

--Query 1
CREATE VIEW 
UserDetails AS 
SELECT * FROM [User];

SELECT * from UserDetails;

--Query 2
CREATE VIEW UserATMCardDetails AS 
SELECT u.name, u.phoneNum, u.city, c.cardNum 
FROM [User] u INNER JOIN UserCard c ON u.userID = c.userID;

SELECT * from UserATMCardDetails;

--Query 3
CREATE PROCEDURE GetUserDetails 
    @name VARCHAR(50)
AS
BEGIN
    SELECT *
    FROM [User]
    WHERE name = @name;
END;
EXEC GetUserDetails  'ALI';

--Query 4
CREATE PROCEDURE GetMinimumBalance 
    @minBalance DECIMAL(18,2) OUTPUT
AS
BEGIN
    SELECT @minBalance = MIN(balance)
    FROM [Card];
END;
DECLARE @min_balance INT; 
EXEC GetMinimumBalance @min_balance OUTPUT; 
SELECT @min_balance AS 'Minimum Balance';

--Query 5
CREATE PROCEDURE GetNumberOfCards 
    @name VARCHAR(50),
    @userID INT,
    @numOfCards INT OUTPUT
AS
BEGIN
    SELECT @numOfCards = COUNT(*)
    FROM [UserCard]
    WHERE userID = @userID AND EXISTS (SELECT * FROM [User] WHERE name = @name AND userID = @userID);
END;
DECLARE @cardCount INT;
EXEC GetNumberOfCards 'Ali', 1, @cardCount OUTPUT;
SELECT @cardCount AS 'Card Count';

--Query 6
CREATE PROCEDURE Login 
    @cardNum VARCHAR(16),
    @PIN VARCHAR(4),
    @status INT OUTPUT
AS
BEGIN
    IF EXISTS (SELECT * FROM [Card] WHERE cardNum = @cardNum AND PIN = @PIN)
        SET @status = 1;
    ELSE
        SET @status = 0;
END;
DECLARE @check BIT
EXEC Login '1234', '1770', @check OUTPUT
SELECT @check AS Status;

--Query 7
CREATE PROCEDURE UpdatePIN 
    @cardNum VARCHAR(16),
    @oldPIN VARCHAR(4),
    @newPIN VARCHAR(4)
AS
BEGIN
    DECLARE @validLength BIT = 0;
    IF LEN(@newPIN) = 4
        SET @validLength = 1;

    IF @validLength = 1 AND EXISTS (SELECT * FROM [Card] WHERE cardNum = @cardNum AND PIN = @oldPIN)
    BEGIN
        UPDATE [Card]
        SET PIN = @newPIN
        WHERE cardNum = @cardNum;
        PRINT 'Updated PIN';
    END
    ELSE
        PRINT 'Error';
END;
EXEC UpdatePIN '1234', '1770', '1337';

ALTER TABLE [Transaction]
ADD TransType int;

--Query 8
CREATE PROCEDURE WithDraw
    @cardNum VARCHAR(16),
    @pin VARCHAR(4),
    @amount MONEY
AS
BEGIN
    DECLARE @status BIT
    EXEC Login @cardNum, @pin, @status OUTPUT
    IF @status = 1 
    BEGIN
        DECLARE @balance MONEY
        SELECT @balance = balance
        FROM [Card]
        WHERE cardNum = @cardNum
        
        IF @balance >= @amount 
        BEGIN
            BEGIN TRANSACTION
            DECLARE @transID INT
            SELECT @transID = ISNULL(MAX(transID), 0) + 1
            FROM [Transaction]

            INSERT INTO [Transaction] (transID,transDate, cardNum, amount,TransType)
            VALUES (@transID,'2023-03-27',@cardNum, @amount, 1)

            UPDATE [Card]
            SET balance = balance - @amount
            WHERE cardNum = @cardNum

            COMMIT TRANSACTION
        END
        ELSE 
        BEGIN
            DECLARE @trans_ID INT
            SELECT @trans_ID = ISNULL(MAX(transID), 0) + 1
            FROM [Transaction]

            INSERT INTO [Transaction] (transID,transDate, cardNum, amount, TransType)
            VALUES (@trans_ID,'2023-03-26',@cardNum, @amount, 4)
        END
    END
END
EXEC WithDraw '1234', '1337', 1000;
SELECT * FROM [Transaction] WHERE CardNum = '1234';
