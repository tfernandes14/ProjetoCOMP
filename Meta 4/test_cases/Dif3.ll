declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
define void @main(i32,i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%i = alloca i32
%.1 = add i32 0, 3
store i32 %.1, i32* %i
%j = alloca double
%.2 = add i32 0, 4
%.3 = sitofp i32 %.2 to double
store double %.3, double* %j
%.4 = load i32 , i32* %i
%.5 = add i32 0, 1
%.6 = add i32 %.4, %.5
%.7 = load double , double* %j
%.8 = sitofp i32 %.6 to double
%.9 = fcmp oeq double %.8, %.7
br i1 %.9, label %then0, label %else0
then0:
%.10 = load double , double* %j
%.11 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.10)
br label %ifCont0
else0:
br label %ifCont0
ifCont0:
ret void 
}
