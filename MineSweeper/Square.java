/**
 * Name : Sebastian Melendez
 * PennKey : sebm
 * Recitation : 200214
 * 
 * Execution: java Square, won't run because no main fuction. 
 * 
 * Program Description: This program is a constructor that creates the different 
 *                      types of square.
 */
public class Square {
  
  private boolean mine; 
  private int number;
  private double lowerPosX;
  private double upperPosX; 
  private double lowerPosY; 
  private double upperPosY; 
  private int centerX; 
  private int centerY;
  private int type; 
  private String picture; 
  private boolean isOpen;
  
  /*
   * Description: This is the constructor that places the mines and the numbers. 
   * Input: It take in a mine boolean to determine if it is a mine or not, a number 
   *        to determine what number should be placed, 4 doubles that determine the 
   *        edges of each square, two ints that determine the center of each square, 
   *        an integer that determines the type either a 1 for a mine and a 2 for a 
   *        number. a string for the name of the picture, and a boolean of whether
   *        or not the square has been clicked or not. 
   * Output: There is not output but set up of the square constructor. 
   */
  public Square(boolean mine, int number, double upperPosX, double lowerPosX, 
                double upperPosY, double lowerPosY, int centerX, int centerY, 
                int type, String picture, boolean isOpen) {
    this.mine = mine; 
    this.number = number; 
    this.upperPosX = upperPosX;
    this.lowerPosX = lowerPosX;  
    this.upperPosY = upperPosY; 
    this.lowerPosY = lowerPosY;
    this.centerX = centerX; 
    this.centerY = centerY; 
    this.type = type; 
    this.picture = picture; 
    this.isOpen = isOpen;
  }
  
  /*
   * Description: This is the constructor for the null squares. 
   * Input: It take in 4 doubles that determine the edges of each square, two ints 
   *        that determines the center of each square, 
   *        an integer that determines the type either a 0 for a null space and a 3 
   *        one of the first squares touched. a string for the name of the picture, 
   *        and a boolean of whether or not the square has been clicked or not.
   * Output: There is not output but this sets up of the square constructor.
   */  
  public Square(double upperPosX, double lowerPosX, double upperPosY, 
                double lowerPosY, int centerX, int centerY, int type, 
                boolean isOpen) { 
    this.upperPosX = upperPosX;
    this.lowerPosX = lowerPosX;  
    this.upperPosY = upperPosY; 
    this.lowerPosY = lowerPosY;
    this.centerX = centerX; 
    this.centerY = centerY; 
    this.type = type; 
    this.isOpen = isOpen; 
  }
  
  /*
   * Description: This function gets whether it is a mine or not. 
   * Input: There is no input but it is called on a object. 
   * Output: This returns a boolean that determines wher it is a mine or not. 
   */  
  public boolean getMine() {
    return this.mine;   
  }
  
  /*
   * Description: This method get the number of mines touching the square.
   * Input: There is no input but it is called on a object. 
   * Output: This returns an int that is the number of mines touching the square. 
   */  
  public int getNumber() {
    return this.number; 
  }
  
  /*
   * Description: This sets the number of the amount of mines touching the squares. 
   * Input: The input is the number of mines touching a square and it is called on 
   *        a object. 
   * Output: the output is void. 
   */  
  public void setNumber(int newNumber) {
    this.number = newNumber;
  }

  /*
   * Description: This method gets an integer that refers to the type.  
   * Input: It is called on a object. no imput. 
   * Output: this returns a interger of the type of square.  
   */ 
  
  public int getType() {
    return this.type;  
  }
  
  
  /*
   * Description: This sets the lower X position of the square. 
   * Input: the input is the lower X position as a double, it is called on a object. 
   * Output: the output is void. 
   */  
  public void setLowerPosX(double posX) {
    this.lowerPosX = posX; 
  }

  /*
   * Description: This method gets an double that refers to the lower X position.  
   * Input: It is called on a object. no imput. 
   * Output: this returns a double that is the lower X position 
   */ 
  public double getLowerPosX() {
    return this.lowerPosX;
  }
  

  
  /*
   * Description: This sets the upper X position of the square. 
   * Input: the input is the uppper X position as a double, it is called on a 
   *        object.
   * Output: the output is void.   
   */
  public void setUpperPosX(double posX) {
    this.upperPosX = posX; 
  } 
  
  /*
   * Description: This method gets an double that refers to the upper X position.  
   * Input: It is called on a object. no imput. 
   * Output: this returns a double that is the upper X position 
   */  
  public double getUpperPosX() {
    return this.upperPosX;
  }
  
  /*
   * Description: This sets the lower Y position of the square. 
   * Input: the input is the lower Y position as a double, it is called on a object.
   * Output: the output is void.   
   */  
  public void setLowerPosY(double posY) {
    this.lowerPosY = posY; 
  } 

  /*
   * Description: This method gets an double that refers to the lower Y position.  
   * Input: It is called on a object. no imput. 
   * Output: this returns a double that is the lower Y position 
   */   
  public double getLowerPosY() {
    return this.lowerPosY;
  }
  
  /*
   * Description: This sets the upper Y position of the square.
   * Input: the input is the upper Y position as a double, it is called on a object.
   * Output: the output is void.  
   */
  public void setUpperPosY(double posY) {
    this.upperPosY = posY; 
  } 
  
  /*
   * Description: This method gets an double that refers to the upper Y position.  
   * Input: It is called on a object. no imput. 
   * Output: this returns a double that is the upper Y position 
   */ 
  public double getUpperPosY() {
    return this.upperPosY;
  }

  /*
   * Description: This sets the center x position of the square. 
   * Input: the input is the center X position as a int, it is called on a object.
   * Output: the output is void.  
   */
  public void setCenterX(int posX) {
    this.centerX = posX;
  }

  /*
   * Description: This method gets an int that refers to the center X position.  
   * Input: It is called on a object. no imput. 
   * Output: this returns an int that is the center X position 
   */ 
  public int getCenterX() {
    return this.centerX; 
  }
  
  /*
   * Description: This sets the center Y position of the square. 
   * Input: the input is the center Y position as a int, it is called on a object.
   * Output: the output is void.   
   */
  public void setCenterY(int posY) {
    this.centerY = posY; 
  }
 
  /*
   * Description: This method gets an int that refers to the center Y position.  
   * Input: It is called on a object. no imput. 
   * Output: this returns an int that is the center Y position 
   */
  public int getCenterY() {
    return this.centerY; 
  }
  
  /*
   * Description: This sets the name of the needed picture to the square to later 
   *              be drawn. 
   * Input: This sets the name of the picture used as a string. It is called on an 
   *        object. 
   * Output: the output is void.  
   */
  public void setPicture(String pic) {
    this.picture = pic;
  }
 
  /*
   * Description: This method gets a string that refers to the picture  
   * Input: It is called on a object. no imput. 
   * Output: this returns a String that is the name of the necesary image 
   */
  public String getPicture() {
    return this.picture;
  }
  
  /*
   * Description: This sets the boolean to true and says the spot is open. 
   * Input: There is no input. 
   * Output: the output is void.  
   */   
  public void setOpen() {
    this.isOpen = true;
  }
  
  /*
   * Description: This method gets a boolean that refers to the if a square has been
   *              clicked
   * Input: It is called on a object. no imput. 
   * Output: this returns a boolean that it has either been click or not. 
   */  
  public boolean getOpen() {
    return this.isOpen;
  }
  
}