/**
 * Name : Sebastian Melendez
 * PennKey : sebm
 * Recitation : 200214
 * 
 * Execution: java Mindsweeper
 * 
 * Program Description: This program runs the game by using the square constructor
 *                      and a 9 by 9 gameboard. This program places ten mines
 *                      randomly throughout the board and the sets the numbers and 
 *                      the null spaces. It then allows the player to play the 
 *                      minesweeper game. 
 */
public class Mindsweeper {
  public static int totalClosedSpaces = 81; 
  public static boolean firstClick = true; 
 
  /*
   * Description: This function places 10 mines randomly throughout the gameboard. 
   * Input: It takes in an object 2-D array that is to be filled by the number of
   *        mines specified and in this case 10. 
   * Output: It is a void output but it places the mines randomly throughout the 
   *         the gameboard. 
   */   
  public static void placeMines(Square[][] gameBoard, int totalMines) {
    int mines = 0; 
    while (mines < 10) {
      int randomPos = (int) (Math.random() * 100);
      int randomRow; 
      int randomCol;
      if (randomPos == 0) {
        randomRow = 0; 
        randomCol = 0; 
      } else {
        randomRow = randomPos / 10;
        randomCol = randomPos % 10;
      }
      if (randomRow < 9 && randomCol < 9 && 
         gameBoard[randomRow][randomCol] == null) {
        
        double uPosX = 15 + randomRow * 10; 
        double lPosX = 5 + randomRow * 10; 
        double uPosY = 95 - randomCol * 10; 
        double lPosY = 85 - randomCol * 10;
        int cenX = 10 + randomRow * 10; 
        int cenY = 90 - randomCol * 10; 
        
        Square mine = new Square(true, 0, uPosX, lPosX, uPosY, lPosY, cenX, cenY, 1, 
                             "mine.png", false);
        gameBoard[randomRow][randomCol] = mine;
        mines++;
      }
    }
  }
  
  /*
   * Description: This function sets the numbers throughout the gameboard.
   * Input: It takes in an It takes in an object 2-D array.
   * Output: The output is void but the method places and sets the numbers to the 
   *         positions within the array. 
   */    
  public static void setNumbers(Square[][] gameBoard) {   
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        int counter = 0; 
        double uPosX = 15 + row * 10; 
        double lPosX = 5 + row * 10; 
        double uPosY = 95 - col * 10; 
        double lPosY = 85 - col * 10; 
        int cenX = 10 + row * 10; 
        int cenY = 90 - col * 10;
        Square number = new Square(false, counter, uPosX, lPosX, uPosY, lPosY, 
                                   cenX, cenY, 2, "", false); 
        //Rows
        if (gameBoard[row][col] == null || gameBoard[row][col].getType() == 3) {
          if (row + 1 <= 8 && gameBoard[row + 1][col] != null && 
             gameBoard[row + 1][col].getMine())
            counter++; 
          if (row - 1 >= 0 && gameBoard[row - 1][col] != null && 
             gameBoard[row - 1][col].getMine())
            counter++; 
          //Colums
          if (col + 1 <= 8 && gameBoard[row][col + 1] != null && 
             gameBoard[row][col + 1].getMine())
            counter++; 
          if (col - 1 >= 0 && gameBoard[row][col - 1] != null && 
             gameBoard[row][col - 1].getMine())
            counter++; 
          //Corners
          if (row + 1 <= 8 && col + 1 <= 8 && gameBoard[row + 1][col + 1] != null && 
             gameBoard[row + 1][col + 1].getMine())
            counter++; 
          if (row - 1 >= 0 && col + 1 <= 8 && gameBoard[row - 1][col + 1] != null && 
             gameBoard[row - 1][col + 1].getMine())
            counter++;
          if (row + 1 <= 8 && col - 1 >= 0 && gameBoard[row + 1][col - 1] != null && 
             gameBoard[row + 1][col - 1].getMine())
            counter++;
          if (row - 1 >= 0 && col - 1 >= 0 && gameBoard[row - 1][col - 1] != null && 
             gameBoard[row - 1][col - 1].getMine())
            counter++;
          if (counter > 0) {
            number.setNumber(counter);
            gameBoard[row][col] = number; 
          }
          if (counter == 1)
            gameBoard[row][col].setPicture("one.png");
          else if (counter == 2) 
            gameBoard[row][col].setPicture("two.png");
          else if (counter == 3)
            gameBoard[row][col].setPicture("three.png");
          else if (counter == 4)
            gameBoard[row][col].setPicture("four.png");
          else if (counter == 5)
            gameBoard[row][col].setPicture("five.png"); 
          else if (counter == 6)
            gameBoard[row][col].setPicture("six.png"); 
          else if (counter == 7)
            gameBoard[row][col].setPicture("seven.png");
          else if (counter == 8)
            gameBoard[row][col].setPicture("eight.png");                        
        }
      }
    }
  }

  /*
   * Description: This function sets all the positions that are not perviously set 
   *              to null squares, theses are niether mines or number squares. 
   * Input: It takes in an object 2-D array. 
   * Output: The ouutput is void but it sets the empty squares in the array. 
   */    
  public static void setNullSquares(Square[][] gameBoard) {
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        double uPosX = 15 + row * 10; 
        double lPosX = 5 + row * 10; 
        double uPosY = 95 - col * 10; 
        double lPosY = 85 - col * 10; 
        int cenX = 10 + row * 10; 
        int cenY = 90 - col * 10;
        Square emptySpace = new Square(uPosX, lPosX, uPosY, lPosY, 
                                   cenX, cenY, 0, false);
        if (gameBoard[row][col] == null || gameBoard[row][col].getType() == 3) {
          gameBoard[row][col] = emptySpace; 
        }
      }
    }
  }
  
  /*
   * Description: This function draws the initial gameboard. 
   * Input: There is no input.
   * Output: There is no ouput but the board is drawn. 
   */    
  public static void draw() {
    PennDraw.setYscale(0, 100);
    PennDraw.setXscale(0, 100);
    int x = 10;
    int y = 90; 
    PennDraw.setPenRadius(.005);
    for (int i = 0; i < 81; i++) {
      PennDraw.setPenColor(PennDraw.DARK_GRAY);
      PennDraw.filledSquare(x, y, 5);
      PennDraw.setPenColor(PennDraw.GRAY);
      PennDraw.square(x, y, 5);
      x += 10; 
      if (x == 100) {
        y -= 10;
        x = 10; 
      }
      if (y == 0)
        break; 
    } 
  }
  
   /*
   * Description: This function initializes the gameboard by calling all the methods
   *              to set the squares. 
   * Input: It takes in an object 2-D array and the x and y position of the first 
   *        click. 
   * Output: This function is a helper function that initializes and sets the
   *         gameboard. 
   */   
  public static void initializeGame(Square[][] gameBoard, double startPosX, 
                                    double startPosY) {
    findStartSquare(gameBoard, startPosX, startPosY);
    placeMines(gameBoard, 10);
    setNumbers(gameBoard);
    setNullSquares(gameBoard);
  }  
  
  /*
   * Description: This function finds the first square that is touched and ensures 
   *              it is always null. 
   * Input: It takes in an object 2-D array, and two double that represent the 
   *        x and y positions of the first click. 
   * Output: There is no output but the functions determines the row and column 
   *         of the first click and then sets the positon. It allows for the
   *         surrounding squares to not be set as mines. 
   */    
  public static void findStartSquare(Square[][] gameBoard, double startPosX, 
                                     double startPosY) {
    System.out.println("alsdkjfj");
    int row = 0; 
    int col = 0; 
    double posX = startPosX;
    double posY = 100 - startPosY;
    if (posX % 10 < 5)
      row = (int) (((posX - (posX % 10)) / 10) - 1);
    else if (posX % 10 > 5)
      row = (int) ((posX - (posX % 10)) / 10); 
    
    if (posY % 10 > 5)
      col = (int) ((posY - (posY % 10)) / 10);
    else if (posY % 10 < 5)
      col = (int) (((posY - (posY % 10)) / 10) - 1);
    
    double uPosX = 15 + row * 10; 
    double lPosX = 5 + row * 10; 
    double uPosY = 95 - col * 10; 
    double lPosY = 85 - col * 10; 
    int cenX = 10 + row * 10; 
    int cenY = 90 - col * 10;
    Square emptySpace = new Square(uPosX, lPosX, uPosY, lPosY, cenX, cenY, 0, 
                                   false); 
    click(emptySpace);
    setSurroundingSquares(gameBoard, row, col);
  }
  
  /*
   * Description: This fuction sets the surrounding squares so the first square is
   *              not a mine.
   * Input: It takes in a gameboard 2-D array and the initial row and column. 
   * Output: This fuction sets the surrounding squares not to null so that the first 
   *         click is not a mine or a number.
   */    
  public static void setSurroundingSquares(Square[][] gameBoard, int row, int col) {
    System.out.println("hehehehe");
    //row + 1
    if (row + 1 <= 8)
      gameBoard[row + 1][col] = new Square(15 + ((row + 1) * 10), 
                                                5 + ((row + 1) * 10), 
                                                95 - col * 10, 85 - col * 10, 
                                                10 + ((row + 1) * 10), 
                                                90 - col * 10, 3, false);
    
    //row - 1
    if (row - 1 >= 0)
      gameBoard[row - 1][col] = new Square(15 + ((row - 1) * 10), 
                                                5 + ((row - 1) * 10), 
                                                95 - col * 10, 85 - col * 10, 
                                                10 + ((row - 1) * 10), 
                                                90 - col * 10, 3, false);
    
    //col + 1
    if (col + 1 <= 8)
      gameBoard[row][col + 1] = new Square(15 + row * 10, 5 + row * 10, 
                                                95 - ((col + 1) * 10), 
                                                85 - ((col + 1) * 10), 
                                                10 + row * 10, 
                                                90 - ((col + 1) * 10), 3, false);
    
    //col - 1
    if (col - 1 >= 0)
      gameBoard[row][col - 1] = new Square(15 + row * 10, 5 + row * 10, 
                                                95 - ((col - 1) * 10), 
                                                85 - ((col - 1) * 10), 
                                                10 + row * 10, 
                                                90 - ((col - 1) * 10), 3, false);
    
    //row + 1 col + 1
    if (row + 1 <= 8 && col + 1 <= 8)
      gameBoard[row + 1][col + 1] = new Square(15 + ((row + 1) * 10), 
                                                    5 + ((row + 1) * 10), 
                                                    95 - ((col + 1) * 10), 
                                                    85 - ((col + 1) * 10), 
                                                    10 + ((row + 1) * 10), 
                                                    90 - ((col + 1) * 10), 
                                                    3, false);
    
    //row - 1 col + 1
    if (row - 1 >= 0 && col + 1 <= 8)
      gameBoard[row - 1][col + 1] = new Square(15 + ((row - 1) * 10), 
                                                    5 + ((row - 1) * 10), 
                                                    95 - ((col + 1) * 10), 
                                                    85 - ((col + 1) * 10), 
                                                    10 + ((row - 1) * 10), 
                                                    90 - ((col + 1) * 10), 
                                                    3, false);
    
    //row + 1 col - 1
    if (row + 1 <= 8 && col - 1 >= 0)
      gameBoard[row + 1][col - 1] = new Square(15 + ((row + 1) * 10), 
                                                    5 + ((row + 1) * 10), 
                                                    95 - ((col - 1) * 10), 
                                                    85 - ((col - 1) * 10), 
                                                    10 + ((row + 1) * 10), 
                                                    90 - ((col - 1) * 10), 
                                                    3, false);
    
    //row - 1 col - 1
    if (row - 1 >= 0 && col - 1 >= 0)
      gameBoard[row - 1][col - 1] = new Square(15 + ((row - 1) * 10), 
                                                    5 + ((row - 1) * 10), 
                                                    95 - ((col - 1) * 10), 
                                                    85 - ((col - 1) * 10), 
                                                    10 + ((row - 1) * 10), 
                                                    90 - ((col - 1) * 10), 
                                                    3, false);
  }
  
  /*
   * Description: This fuctions draws the square that is clicked
   * Input: The input is a specific square within the array which depending on the 
   *        set up is either a null square or a number or mine and draws the correct
   *        one. 
   * Output: There is no ouput but it draws the square.  
   */    
  public static void click(Square space) {
    if (!space.getOpen())
      totalClosedSpaces--;
    if (space.getType() == 0 || space.getType() == 3) {
      PennDraw.setPenColor(PennDraw.LIGHT_GRAY);
      PennDraw.filledSquare(space.getCenterX(), space.getCenterY(), 5);
      PennDraw.setPenRadius(.005);
      PennDraw.setPenColor(PennDraw.GRAY);
      PennDraw.square(space.getCenterX(), space.getCenterY(), 5);
      
      space.setOpen(); 
    } else {
      
      PennDraw.picture(space.getCenterX(), space.getCenterY(), 
                       space.getPicture(), 0, 50);
      PennDraw.setPenColor(PennDraw.GRAY);
      PennDraw.square(space.getCenterX(), space.getCenterY(), 5);
      space.setOpen();
    }
  }
  
  /*
   * Description: This function uses recution to draw all the null squares that are
   *              touching the initial null squares. 
   * Input: It takes in a square 2-D array and the row and column of the click 
   *        of the null square. 
   * Output: The output is void but it drawns squares thats are null and the numbers 
   *         touching those squares. 
   */    
  public static void recuriveEmptySquare(Square[][] gameBoard, int row, int col) {
    if (row < 9 && row >= 0 && col < 9 && col >= 0 && 
       gameBoard[row][col].getType() == 2) {
      click(gameBoard[row][col]);
    } else if (row < 9 && row >= 0 && col < 9 && col >= 0 && 
              gameBoard[row][col].getOpen() == false && 
              (gameBoard[row][col].getType() == 0 || 
               gameBoard[row][col].getType() == 3)) {
      
      click(gameBoard[row][col]);
      recuriveEmptySquare(gameBoard, row + 1, col);
      recuriveEmptySquare(gameBoard, row - 1, col);
      recuriveEmptySquare(gameBoard, row, col + 1);
      recuriveEmptySquare(gameBoard, row, col - 1);
      recuriveEmptySquare(gameBoard, row + 1, col + 1);
      recuriveEmptySquare(gameBoard, row + 1, col - 1);
      recuriveEmptySquare(gameBoard, row - 1, col + 1);
      recuriveEmptySquare(gameBoard, row - 1, col - 1);
    }
  }
  
  /*
   * Description: This function clears the entire gameboard so that a new game can 
   *              be played. 
   * Input: This take in the gameboard 2-D array. 
   * Output: There is no output but the gameboard is the cleared. 
   */  
  public static void clear(Square[][] gameBoard) {
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        gameBoard[row][col] = null;
      }
    }
  }
  
  /*
   * Description: This function runs the entire game by using two while loops that 
   *              play off of eachother. 
   * Input: This function takes in a gameboard, the 2-D array. 
   * Output: There is no output but the game is run by this function. 
   */    
  public static void run(Square[][] gameBoard) {
    draw();
    totalClosedSpaces = 81; 
    boolean condition = true; 
    boolean win = false; 
    while (condition) {
      double x = PennDraw.mouseX();
      double y = PennDraw.mouseY();
      //System.out.println(totalClosedSpaces);
      if (PennDraw.mousePressed() && x > 5 && x < 95 && y > 5 && y < 95) {
        if (firstClick) {
          firstClick = false; 
          initializeGame(gameBoard, x, y);
        } else {
          for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
              if (gameBoard[row][col].getUpperPosX() > x && 
                  gameBoard[row][col].getLowerPosX() < x && 
                  gameBoard[row][col].getUpperPosY() > y && 
                  gameBoard[row][col].getLowerPosY() < y) {
                if (gameBoard[row][col].getType() == 1 && 
                   gameBoard[row][col].getOpen())
                  condition = false;
                else if (totalClosedSpaces == 10 &&
                         !gameBoard[row][col].getMine()) {
                  win = true; 
                  condition = false; 
                }
                if (gameBoard[row][col].getType() == 0)
                  recuriveEmptySquare(gameBoard, row, col); 
                else
                  click(gameBoard[row][col]);
              }
            }
          }
        }
      }
    }
    if (win == false) { 
      PennDraw.picture(50, 50, "gameover.png", 0, 100);
      PennDraw.picture(50, 20, "reset.png", 0, 60);
    } else if (totalClosedSpaces <= 10 && win == true) {
      PennDraw.picture(50, 50, "YouWin.png", 0, 200);
      PennDraw.picture(50, 20, "reset.png", 0, 60);
    }
    
    boolean condition2 = true;
    while (condition2) {
      double x = PennDraw.mouseX();
      double y = PennDraw.mouseY();
      if (PennDraw.mousePressed() && x <= 65 && x >= 35 && y <= 25  && y >= 15) {
        firstClick = true;
        clear(gameBoard); 
        condition2 = false; 
        run(gameBoard);
        
      }
    }

  }

  /*
   * Description: This function is the main method that allows the program to run. 
   * Input: It takes in command line arguments but they are not used in this 
   *        program.
   * Output: There is no output but this method runs the program.  
   */  
  public static void main(String[] args) {
    Square[][] gameBoard = new Square [9][9]; 
    run(gameBoard);
    
  }
}