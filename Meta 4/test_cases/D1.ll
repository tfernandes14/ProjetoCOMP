declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.0 = constant [2 x i8] c"\0A\00"
@.str.1 = constant [24 x i8] c"NAO\09ENTENDO\0CNADADs\0D\0ATO\0A\00"
@.str.2 = constant [2 x i8] c"\0A\00"
@.str.3 = constant [20 x i8] c"TAMO NESSA VANESSA\0A\00"
@.str.4 = constant [2 x i8] c"\0A\00"
@.str.5 = constant [17 x i8] c"JENNIFER TINDER\0A\00"
@.str.6 = constant [2 x i8] c"\0A\00"
@.str.7 = constant [25 x i8] c"NAO ENTENDO NADA DISTO1\0A\00"
@.str.8 = constant [2 x i8] c"\0A\00"
@.str.9 = constant [11 x i8] c"REPETIDO1\0A\00"
@.str.10 = constant [2 x i8] c"\0A\00"
@.str.11 = constant [11 x i8] c"REPETIDO2\0A\00"
@.str.12 = constant [2 x i8] c"\0A\00"
@.str.13 = constant [25 x i8] c"NAO ENTENDO NADA DISTO2\0A\00"
@bool_bool = common global i1 0
@integer_int = common global i32 0
@real_double = common global double 0.0
define i1 @method_bool_bool() {
%i = alloca i1
%.1 = or i1 false, true
store i1 %.1, i1* %i
%.2 = load i1 , i1* %i
br i1 %.2, label %then1, label %else1
then1:
%.3 = call i32 (i8*, ...) @printf(i8* getelementptr ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont1
else1:
%.4 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont1
ifCont1:
%.5 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.0, i32 0, i32 0))
%.6 = call i32 (i8*, ...) @printf(i8* getelementptr ([24 x i8], [24 x i8]* @.str.1, i32 0, i32 0))
%.7 = load i1 , i1* %i
ret i1 %.7
ret i1 0
}
define i1 @method_bool_bool_int(i32 %.a) {
%a = alloca i32
store i32 %.a, i32* %a
%i = alloca i1
%.1 = or i1 false, true
store i1 %.1, i1* %i
%.2 = load i1 , i1* %i
br i1 %.2, label %then2, label %else2
then2:
%.3 = call i32 (i8*, ...) @printf(i8* getelementptr ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont2
else2:
%.4 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont2
ifCont2:
%.5 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.2, i32 0, i32 0))
%.6 = call i32 (i8*, ...) @printf(i8* getelementptr ([20 x i8], [20 x i8]* @.str.3, i32 0, i32 0))
%.7 = load i1 , i1* %i
ret i1 %.7
ret i1 0
}
define i1 @method_bool_bool_double(double %.a) {
%a = alloca double
store double %.a, double* %a
%i = alloca i1
%.1 = or i1 false, true
store i1 %.1, i1* %i
%.2 = load i1 , i1* %i
br i1 %.2, label %then3, label %else3
then3:
%.3 = call i32 (i8*, ...) @printf(i8* getelementptr ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont3
else3:
%.4 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont3
ifCont3:
%.5 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.4, i32 0, i32 0))
%.6 = call i32 (i8*, ...) @printf(i8* getelementptr ([17 x i8], [17 x i8]* @.str.5, i32 0, i32 0))
%.7 = load i1 , i1* %i
ret i1 %.7
ret i1 0
}
define i32 @method_integer_int() {
%i = alloca i32
%.1 = add i32 0, 1
store i32 %.1, i32* %i
%.2 = load i32 , i32* %i
%.3 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.2)
%.4 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.6, i32 0, i32 0))
%.5 = call i32 (i8*, ...) @printf(i8* getelementptr ([25 x i8], [25 x i8]* @.str.7, i32 0, i32 0))
%.6 = load i32 , i32* %i
ret i32 %.6
ret i32 0
}
define i32 @method_integer_int_int(i32 %.a) {
%a = alloca i32
store i32 %.a, i32* %a
%i = alloca i32
%.1 = add i32 0, 1
%.2 = sub i32 0, %.1
store i32 %.2, i32* %i
%.3 = load i32 , i32* %i
%.4 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.3)
%.5 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.8, i32 0, i32 0))
%.6 = call i32 (i8*, ...) @printf(i8* getelementptr ([11 x i8], [11 x i8]* @.str.9, i32 0, i32 0))
%.7 = load i32 , i32* %i
ret i32 %.7
ret i32 0
}
define i32 @method_integer_int_int_double(i32 %.a,double %.b) {
%a = alloca i32
store i32 %.a, i32* %a
%b = alloca double
store double %.b, double* %b
%i = alloca i32
%.1 = add i32 0, 1
store i32 %.1, i32* %i
%.2 = load i32 , i32* %i
%.3 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.2)
%.4 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.10, i32 0, i32 0))
%.5 = call i32 (i8*, ...) @printf(i8* getelementptr ([11 x i8], [11 x i8]* @.str.11, i32 0, i32 0))
%.6 = load i32 , i32* %i
ret i32 %.6
ret i32 0
}
define double @method_real_double() {
%i = alloca double
%.1 = fadd double 0.000000, 1.0000000000000000e+00
store double %.1, double* %i
%.2 = load double , double* %i
%.3 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.2)
%.4 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.12, i32 0, i32 0))
%.5 = call i32 (i8*, ...) @printf(i8* getelementptr ([25 x i8], [25 x i8]* @.str.13, i32 0, i32 0))
%.6 = load double , double* %i
ret double %.6
ret double 0.0
}
define void @main(i32,i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%.1 = call i1 @method_bool_bool()
%.2 = load i32 , i32* @integer_int
%.3 = call i1 @method_bool_bool_int(i32 %.2)
%.4 = load double , double* @real_double
%.5 = call i1 @method_bool_bool_double(double %.4)
%.6 = call i32 @method_integer_int()
%.7 = load i32 , i32* @integer_int
%.8 = call i32 @method_integer_int_int(i32 %.7)
%.9 = add i32 0, 1
%.10 = add i32 0, 2
%.11 = sitofp i32 %.10 to double
%.12 = call i32 @method_integer_int_int_double(i32 %.9,double %.11)
%.13 = call double @method_real_double()
ret void 
}
