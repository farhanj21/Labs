class User 
{
    private String fullName;
    private String lastName;
    private String emailAddress;
    private String phoneNum;
    
    public User(String fullName, String lastName, String emailAddress, String phoneNum) 
    {
        this.fullName = fullName;
        this.lastName = lastName;
        this.emailAddress = emailAddress;
        this.phoneNum = phoneNum;
    }
    
    public String getFirstName() { return fullName; }
    public String getLastName() { return lastName; }
    public String getEmail() { return emailAddress; }
    public String getPhoneNo() { return phoneNum; }
    
    public void setFirstName(String fullName) { this.fullName = fullName; }
    public void setLastName(String lastName) { this.lastName = lastName; }
    public void setEmail(String emailAddress) { this.emailAddress = emailAddress; }
    public void setPhoneNo(String phoneNum) { this.phoneNum = phoneNum; }
    
    public void signUp() {}
    public void forgotPassword() {}
    public void resetPassword() {}
    public void updateProfile() {}

}

class Admin extends User 
{
    public Admin(String fullName, String lastName, String emailAddress, String phoneNum) 
    {
        super(fullName, lastName, emailAddress, phoneNum);
    }
    
    public void createUser(String fullName, String lastName, String emailAddress, String phoneNum) {}
    public void addUser(String fullName, String phoneNum) {}
    public void deleteUser(String fullName,String phoneNum) {}
    public boolean approveBooking() {return true;}
}

class Customer extends User
{
    public Customer(String fullName, String lastName, String emailAddress, String phoneNum) {
        super(fullName, lastName, emailAddress, phoneNum);
    }
    
    public void viewCars() {}
    public void bookCar(String name, String phoneNumber) {}
}

class CarVendor extends User 
{
    public String type;
    public String carNum;
    
    public CarVendor(String fullName, String lastName, String emailAddress, String phoneNum) 
    {
        super(fullName, lastName, emailAddress, phoneNum);
    }
    
    public void uploadDoc() {}
    
    public void trackCar(String carNumber) 
    {
        System.out.println("Tracking location of car with number: " + carNumber);
    }
    
    public boolean approveBooking() {return true;}
    
}


