interface ToyDuck {
    void squeak();
}

class Bird 
{
    public void fly() {
        System.out.println("Flying...");
    }
    
    public void makeSound() 
    {
        System.out.println("Chirp chirp!");
    }
}

class BirdAdapter implements ToyDuck 
{
    private Bird bird;
    
    public BirdAdapter(Bird bird) 
    {
        this.bird = bird;
    }
    
    public void squeak() {
        bird.makeSound();
    }
}

class Client 
{
    public static void main(String[] args) {
        Bird bird = new Bird();
        ToyDuck toyDuck = new BirdAdapter(bird);
        
 
        toyDuck.squeak();
    }
}
