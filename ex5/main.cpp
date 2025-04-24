// 基礎Car類別 (SuperClass/BaseClass)
class Car {
    protected String brand;
    protected String driveMode;
    
    public Car(String brand, String driveMode) {
        this.brand = brand;
        this.driveMode = driveMode;
        System.out.println("Constructing " + this.getClass().getSimpleName());
        System.out.println(brand + " : Drive Mode = " + driveMode);
    }
    
    public void drive() {
        System.out.println(brand + " is driving with " + driveMode + " drive mode");
    }
}

// BMW車子類別，使用後輪驅動
class BMW_Car extends Car {
    public BMW_Car() {
        super("BMW", "Rear-wheel");
    }
}

// AUDI車子類別，使用前輪驅動
class AUDI_Car extends Car {
    public AUDI_Car() {
        super("Audi", "Front-wheel");
    }
}

// BENZ車子類別，使用前輪驅動
class BENZ_Car extends Car {
    public BENZ_Car() {
        super("Benz", "Front-wheel");
    }
}

// 主程式測試類別
public class CarTest {
    public static void main(String[] args) {
        System.out.println("創建與測試汽車物件：");
        
        BMW_Car bmw = new BMW_Car();
        AUDI_Car audi = new AUDI_Car();
        BENZ_Car benz = new BENZ_Car();
        
        System.out.println("\n測試驅動方法：");
        bmw.drive();
        audi.drive();
        benz.drive();
    }
}
