class Main {

    public static boolean bool;
    public static int integer;
    public static double real;

    public static boolean bool(){
        boolean i;
        i=true;
        System.out.print(i);
        System.out.print("\n");
        System.out.print("NAO\tENTENDO\fNADADs\r\nTO\n");
        return i;
    }

    public static boolean bool(int a){
        boolean i;
        i=true;
        System.out.print(i);
        System.out.print("\n");
        System.out.print("TAMO NESSA VANESSA\n");
        return i;
    }

    public static boolean bool(double a){
        boolean i;
        i=true;
        System.out.print(i);
        System.out.print("\n");
        System.out.print("JENNIFER TINDER\n");
        return i;
    }

    public static int integer(){
        int i;
        i=1;
        System.out.print(i);
        System.out.print("\n");
        System.out.print("NAO ENTENDO NADA DISTO1\n");
        return i;
    }

    public static int integer(int a){
        int i;
        i=-1;
        System.out.print(i);
        System.out.print("\n");
        System.out.print("REPETIDO1\n");
        return i;
    }

    public static int integer(int a , double b){
        int i;
        i=1;
        //i = 2 + i
        System.out.print(i);
        System.out.print("\n");
        System.out.print("REPETIDO2\n");
        return i;
    }

    public static double real(){
        double i;
        i=1.0;
        System.out.print(i);
        System.out.print("\n");
        System.out.print("NAO ENTENDO NADA DISTO2\n");
        return i;
    }


    public static void main(String[] args) {
        bool();
        bool(integer);
        bool(real);
        integer();
        integer(integer);
        integer(1,2);
        real();
    }
}