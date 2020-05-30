declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.0 = constant [2 x i8] c"\0A\00"
@.str.1 = constant [2 x i8] c"\0A\00"
@.str.2 = constant [2 x i8] c"\0A\00"
@.str.3 = constant [23 x i8] c"Teste\09de \0Cstring\5C\22%%%%\00"
@.str.4 = constant [2 x i8] c"\0A\00"
@.str.5 = constant [2 x i8] c"\0A\00"
@.str.6 = constant [2 x i8] c"\0A\00"
@.str.7 = constant [2 x i8] c"\0A\00"
@.str.8 = constant [2 x i8] c"\0A\00"
@.str.9 = constant [2 x i8] c"\0A\00"
@.str.10 = constant [2 x i8] c"\0A\00"
@.str.11 = constant [2 x i8] c"\0A\00"
@a_int = common global i32 0
@b_int = common global i32 0
@c_int = common global i32 0
@d_int = common global i32 0
define void @main.entry(i32 %.size.,i8** %.args) {
%size. = alloca i32
store i32 %.size., i32* %size.%args = alloca i8**
store i8** %.args, i8*** %args
%.1 = add i32 0, 2
store i32 %.1, i32* @a_int
%.2 = load i32 , i32* @a_int
%.3 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.2)
%.4 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.0, i32 0, i32 0))
%i = alloca i32
%a = alloca i32
%i1 = alloca i32
%i2 = alloca i32
%i3 = alloca i32
%d = alloca double
%.5 = add i32 0, 0
%.6 = add i32 0, 3
%.7 = add i32 %.5, %.6
store i32 %.7, i32* %a
%.8 = sitofp i32 %.7 to double
store double %.8, double* %d
%.9 = load i32 , i32* %a
%.10 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.9)
%.11 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.1, i32 0, i32 0))
%.12 = load double , double* %d
%.13 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.12)
%.14 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.2, i32 0, i32 0))
%.15 = call i32 (i8*, ...) @printf(i8* getelementptr ([23 x i8], [23 x i8]* @.str.3, i32 0, i32 0))
%.16 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.4, i32 0, i32 0))
%.17 = load i32 , i32* %a
%.18 = add i32 0, 1
%.19 = add i32 %.17, %.18
store i32 %.19, i32* %a
%.20 = add i32 0, 0
%.21 = icmp sgt i32 %.19, %.20
%.22 = load i32 , i32* %a
%.23 = add i32 0, 3
%.24 = add i32 %.22, %.23
store i32 %.24, i32* %a
%.25 = add i32 0, 0
%.26 = icmp sgt i32 %.24, %.25
%.27 = or i1 %.21, %.26
br i1 %.27, label %then1, label %else1
then1:
%.28 = call i32 (i8*, ...) @printf(i8* getelementptr ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont1
else1:
%.29 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont1
ifCont1:
%.30 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.5, i32 0, i32 0))
%.31 = load i32 , i32* %a
%.32 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.31)
%.33 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.6, i32 0, i32 0))
%.34 = load i32 , i32* %a
%.35 = add i32 0, 1
%.36 = add i32 %.34, %.35
store i32 %.36, i32* %a
%.37 = add i32 0, 0
%.38 = icmp slt i32 %.36, %.37
%.39 = load i32 , i32* %a
%.40 = add i32 0, 3
%.41 = add i32 %.39, %.40
store i32 %.41, i32* %a
%.42 = add i32 0, 0
%.43 = icmp slt i32 %.41, %.42
%.44 = and i1 %.38, %.43
br i1 %.44, label %then2, label %else2
then2:
%.45 = call i32 (i8*, ...) @printf(i8* getelementptr ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont2
else2:
%.46 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont2
ifCont2:
%.47 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.7, i32 0, i32 0))
%.48 = load i32 , i32* %a
%.49 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.48)
%.50 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.8, i32 0, i32 0))
%.51 = fadd double 0.000000, 1.2299999999999999e-08
store double %.51, double* %d
%.52 = load double , double* %d
%.53 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.52)
%.54 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.9, i32 0, i32 0))
%.55 = fadd double 0.000000, 0.0000000000000000e+00
store double %.55, double* %d
%.56 = load double , double* %d
%.57 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.56)
%.58 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.10, i32 0, i32 0))
%.59 = fadd double 0.000000, 1.0000000000000000e+00
store double %.59, double* %d
%.60 = load double , double* %d
%.61 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.60)
%.62 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.11, i32 0, i32 0))
ret void
}
define i32 @main(i32 %.size,i8** %.args){
call void @main.entry(i32 %.size, i8** %.args)
ret i32 0
}
