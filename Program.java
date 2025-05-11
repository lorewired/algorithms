class Program {
  public static void main(String[] args) {
    System.out.println(equal_digits(111111));
  }

  public static boolean equal_digits(int n) {
    int n_log = (int)Math.log10(n);
    int div = 0;
    for(int i = 0; i <= n_log; i++) {
      div *= 10;
      div++;
    }
    return n % div == 0;
  }
}