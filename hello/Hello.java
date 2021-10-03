import java.util.Arrays;

class Hello {
    public static void main(String[] args) {
        int n = 1_000_001;
        int[] a = new int[n];
        Arrays.parallelSetAll(a, x -> isPrime(x) ? 1 : 0);
        System.out.println("Hello World!");
    }

    private static boolean isPrime(int n) {
        int k = 2;
        while (k * k <= n && n % k != 0)
            k++;
        return n >= 2 && k * k > n;
    }
}