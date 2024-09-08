
public class PPPart2 {

    public static void main(String[] args) {
        
        PPPart2 count = new PPPart2();

        Thread t1 = new Thread(() -> count.countUp());

        Thread t2 = new Thread(() -> {
            try {
                t1.join();
            } catch (InterruptedException e) {
                System.out.println("not working?");
            }
            count.countDown();
        });

        t1.start();
        t2.start();
    }

    public void countUp() {
        System.out.println("Thread 1 count up to 20: ");
        for (int i = 0; i <= 20; i++) {
            System.out.print(i + " ");
        }
        System.out.println("");
    }

    public void countDown() {
        System.out.println("Thread 2 count down to 0: ");
        for(int j = 20; j >= 0; j--) {
            System.out.print(j + " ");
        }
    }
}