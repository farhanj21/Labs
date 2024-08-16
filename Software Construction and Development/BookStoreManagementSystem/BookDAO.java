import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class BookDAO  {
    private Connection connection;

    public BookDAO(Connection connection) {
        this.connection = connection;
    }

    public void addBook(Book book) throws SQLException {
        PreparedStatement ps = connection.prepareStatement("INSERT INTO books(title, author, price, inventory_count) VALUES (?, ?, ?, ?)");
        ps.setString(1, book.getTitle());
        ps.setString(2, book.getAuthor());
        ps.setDouble(3, book.getPrice());
        ps.setInt(4, book.getInventoryCount());
        ps.executeUpdate();
    }


    public Book getBookById(int id) throws SQLException {
        PreparedStatement ps = connection.prepareStatement("SELECT * FROM books WHERE book_id = ?");
        ps.setInt(1, id);
        ResultSet rs = ps.executeQuery();
        if (rs.next()) {
            return new Book(rs.getInt("book_id"), rs.getString("title"), rs.getString("author"), rs.getDouble("price"), rs.getInt("inventory_count"));
        }
        return null;
    }

    public List<Book> getAllBooks() throws SQLException {
        List<Book> books = new ArrayList<>();
        Statement st = connection.createStatement();
        ResultSet rs = st.executeQuery("SELECT * FROM books");
        while (rs.next()) {
            books.add(new Book(rs.getInt("book_id"), rs.getString("title"), rs.getString("author"), rs.getDouble("price"), rs.getInt("inventory_count")));
        }
        return books;
    }


    public void updateBook(Book book) throws SQLException {
        PreparedStatement ps = connection.prepareStatement("UPDATE books SET title=?, author=?, price=?, inventory_count=? WHERE book_id=?");
        ps.setString(1, book.getTitle());
        ps.setString(2, book.getAuthor());
        ps.setDouble(3, book.getPrice());
        ps.setInt(4, book.getInventoryCount());
        ps.setInt(5, book.getBookId());
        ps.executeUpdate();
    }

    // DELETE
    public void deleteBook(int bookId) throws SQLException {
        PreparedStatement ps = connection.prepareStatement("DELETE FROM books WHERE book_id=?");
        ps.setInt(1, bookId);
        ps.executeUpdate();
    }
}
class Book {
    private int bookId;
    private String title;
    private String author;
    private double price;
    private int inventoryCount;


    public Book() {}

    public Book(int bookId, String title, String author, double price, int inventoryCount) {
        this.bookId = bookId;
        this.title = title;
        this.author = author;
        this.price = price;
        this.inventoryCount = inventoryCount;
    }

    public int getBookId() {
        return bookId;
    }

    public void setBookId(int bookId) {
        this.bookId = bookId;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getInventoryCount() {
        return inventoryCount;
    }

    public void setInventoryCount(int inventoryCount) {
        this.inventoryCount = inventoryCount;
    }
}
