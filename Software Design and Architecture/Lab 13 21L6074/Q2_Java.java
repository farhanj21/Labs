abstract class Fighter {
    protected KickBehavior kickBehavior;
    protected JumpBehavior jumpBehavior;

    public void performKick() {
        kickBehavior.kick();
    }

    public void performJump() {
        jumpBehavior.jump();
    }

    public void setKickBehavior(KickBehavior kb) {
        kickBehavior = kb;
    }

    public void setJumpBehavior(JumpBehavior jb) {
        jumpBehavior = jb;
    }

    
    public abstract void display();
}

class BasicFighter extends Fighter {
    public BasicFighter() {
        kickBehavior = new BasicKick();
        jumpBehavior = new BasicJump();
    }

    @Override
    public void display() {
        System.out.println("I am a basic fighter");
    }
}

interface KickBehavior {
    public void kick();
}

class BasicKick implements KickBehavior {
    @Override
    public void kick() {
        System.out.println("Performing basic kick");
    }
}

class SpecialKick implements KickBehavior {
    @Override
    public void kick() {
        System.out.println("Performing special kick");
    }
}

interface JumpBehavior {
    public void jump();
}

 class BasicJump implements JumpBehavior {
    @Override
    public void jump() {
        System.out.println("Performing basic jump");
    }
}

class SpecialJump implements JumpBehavior {
    @Override
    public void jump() {
        System.out.println("Performing special jump");
    }
}


