import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        int[] numbers = new int[n];
        for(int i=0; i<n; i++) {
            numbers[i] = sc.nextInt();
        }
        
        int min_value = Integer.MAX_VALUE;
        for(int i=0; i<n; i++){
            min_value = Math.min(min_value, numbers[i]);
        }
        
        for(int i=0; i<n; i++) {
            if(numbers[i]%min_value != 0) {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(min_value);
        return;
    }
}
