class Factorial {
    public static boolean b;

    public static boolean f(){
        d = 1;
        return b;
    } 

    public static int factorial(int n) {
        if (n == 0)
            return 1;
        return n * factorial(n-1);
    }

    public static void main(String[] args) {
        int argument;
        argument = Integer.parseInt(args[0]);
        System.out.print(args.length);
        System.out.print(argument.length);
        System.out.print(factorial(argument));
    }

    public static int d;
}
