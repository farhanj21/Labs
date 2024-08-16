CREATE  database library;
use library;
CREATE TABLE books (
                       book_id INT PRIMARY KEY AUTO_INCREMENT,
                       title VARCHAR(255) NOT NULL,
                       author VARCHAR(255),
                       price DECIMAL(10, 2) NOT NULL,
                       inventory_count INT NOT NULL
);


CREATE TABLE customers (
                           customer_id INT PRIMARY KEY AUTO_INCREMENT,
                           first_name VARCHAR(255) NOT NULL,
                           last_name VARCHAR(255) NOT NULL,
                           email VARCHAR(255) UNIQUE NOT NULL
);


CREATE TABLE orders (
                        order_id INT PRIMARY KEY AUTO_INCREMENT,
                        customer_id INT,
                        order_date DATE NOT NULL,
                        total DECIMAL(10, 2) NOT NULL,
                        FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);


CREATE TABLE order_details (
                               order_id INT,
                               book_id INT,
                               quantity INT NOT NULL,
                               FOREIGN KEY (order_id) REFERENCES orders(order_id),
                               FOREIGN KEY (book_id) REFERENCES books(book_id)
);


CREATE TABLE users (
                       user_id INT PRIMARY KEY AUTO_INCREMENT,
                       username VARCHAR(255) UNIQUE NOT NULL,
                       password VARCHAR(255) NOT NULL, -- Note: In a real application, passwords would be hashed!
                       role ENUM('CUSTOMER', 'ADMIN') NOT NULL,
                       email VARCHAR(255) UNIQUE NOT NULL
);


ALTER TABLE customers ADD COLUMN user_id INT;
ALTER TABLE customers ADD FOREIGN KEY (user_id) REFERENCES users(user_id);

-- Inserting random data into users and customers tables
INSERT INTO users (username, password, role, email) VALUES
                                                        ('johnDoe', 'password123', 'CUSTOMER', 'johndoe@example.com'),
                                                        ('admin', 'adminpassword', 'ADMIN', 'admin@example.com');

-- Assuming the user_ids generated are 1 and 2 respectively
INSERT INTO customers (user_id, first_name, last_name,email) VALUES
    (1, 'John', 'Doe','johndoe@example.com');

-- Inserting random data into books table
INSERT INTO books (title, author, price, inventory_count) VALUES
                                                              ('The Great Book', 'Author A', 19.99, 10),
                                                              ('Another Book', 'Author B', 14.99, 5),
                                                              ('More Books', 'Author C', 29.99, 3);


INSERT INTO orders (customer_id, order_date, total) VALUES
    (1, '2023-10-29', 34.98); -- Assuming he bought 2 books


INSERT INTO order_details (order_id, book_id, quantity) VALUES
                                                            (1, 1, 1),
                                                            (1, 2, 1);



