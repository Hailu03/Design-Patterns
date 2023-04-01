import java.io.FileWriter;

public class Main {
    public static void main(String[] args) {
        Logger logger1 = Logger.getInstance();
        logger1.log("First log message");

        Logger logger2 = Logger.getInstance();
        logger2.log("Second log message");

        assert logger1 == logger2;  // both logger1 and logger2 refer to the same instance of Logger

    }
}