
/**
 * Shallow Copy Constrcutor Example
 */
class Base {
  public int field_1;
  
  public int field_2;
  
  Base copyBase(Base obj) {
    Base baseCopy = new Base();
    baseCopy.field_1 = obj.field_1;
    baseCopy.field_2 = obj.field_2;
    return baseCopy;
  }
}

public class copyConstructor {
  public static void main(String[] args) {
    
    // * Shallow Copy Constrcutor Example
    Base b = new Base();
    b.field_1 = 1;
    b.field_2 = 2;

    System.out.println(b.copyBase(b) == b);

    // * Deep copy constructor Example 


  }
}
