declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.0 = constant [20 x i8] c"I have two doubles\0A\00"
@.str.1 = constant [19 x i8] c"I have one double\0A\00"
@.str.2 = constant [16 x i8] c"I have one int\0A\00"
@.str.3 = constant [19 x i8] c"I'm the fake main\0A\00"
@.str.4 = constant [2 x i8] c"\0A\00"
@.str.5 = constant [5 x i8] c"\0Aa:\0A\00"
@.str.6 = constant [11 x i8] c"Before if\0A\00"
@.str.7 = constant [11 x i8] c"After ifs\0A\00"
@.str.8 = constant [11 x i8] c"After ifs\0A\00"
@.str.9 = constant [2 x i8] c"\0A\00"
@.str.10 = constant [2 x i8] c"\0A\00"
@.str.11 = constant [14 x i8] c"Before while\0A\00"
@overload_int = common global i32 0
define i1 @method_overload_bool_bool(i1 %.n) {
%n = alloca i1
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr ([20 x i8], [20 x i8]* @.str.0, i32 0, i32 0))
%.2 = or i1 false, true
ret i1 %.2
ret i1 0
}
define double @method_overload_double_double(double %.n) {
%n = alloca double
store double %.n, double* %n
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr ([19 x i8], [19 x i8]* @.str.1, i32 0, i32 0))
%.2 = fadd double 0.000000, 2.2000000000000002e+00
%.3 = add i32 0, 2
%.4 = sitofp i32 %.3 to double
%.5 = fmul double %.2, %.4
%.6 = add i32 0, 2
%.7 = call i32 @method_main_int_int(i32 %.6)
%.8 = add i32 0, 5
%.9 = sdiv i32 %.7, %.8
%.10 = add i32 0, 6
%.11 = mul i32 %.9, %.10
%.12 = sitofp i32 %.11 to double
%.13 = fadd double %.5, %.12
%.14 = add i32 0, 2
%.15 = add i32 0, 3
%.16 = mul i32 %.14, %.15
%.17 = sitofp i32 %.16 to double
%.18 = fadd double %.13, %.17
%.19 = add i32 0, 3
%.20 = add i32 0, 4
%.21 = mul i32 %.19, %.20
%.22 = sitofp i32 %.21 to double
%.23 = fadd double %.18, %.22
%.24 = add i32 0, 2
%.25 = add i32 0, 8
%.26 = mul i32 %.24, %.25
%.27 = sitofp i32 %.26 to double
%.28 = fadd double %.23, %.27
%.29 = add i32 0, 5
%.30 = add i32 0, 9
%.31 = mul i32 %.29, %.30
%.32 = sitofp i32 %.31 to double
%.33 = fadd double %.28, %.32
%.34 = add i32 0, 2
%.35 = add i32 0, 2
%.36 = call i32 @method_overload_int_int_int(i32 %.34,i32 %.35)
%.37 = sitofp i32 %.36 to double
%.38 = fadd double %.33, %.37
ret double %.38
ret double 0.0
}
define i32 @method_overload_int_double_double(double %.b,double %.b1) {
%b = alloca double
store double %.b, double* %b
%b1 = alloca double
store double %.b1, double* %b1
%.1 = add i32 0, 2
%.2 = load i32 , i32* @overload_int
%.3 = add i32 %.1, %.2
store i32 %.3, i32* @overload_int
%overload = alloca double
%.4 = call i32 (i8*, ...) @printf(i8* getelementptr ([16 x i8], [16 x i8]* @.str.2, i32 0, i32 0))
%.5 = add i32 0, 5
ret i32 %.5
ret i32 0
}
define i32 @method_overload_int_int_int(i32 %.b,i32 %.b1) {
%b = alloca i32
store i32 %.b, i32* %b
%b1 = alloca i32
store i32 %.b1, i32* %b1
%.1 = add i32 0, 5
ret i32 %.1
ret i32 0
}
define i32 @main_int(i32 %.n) {
%n = alloca i32
store i32 %.n, i32* %n
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr ([19 x i8], [19 x i8]* @.str.3, i32 0, i32 0))
%.2 = add i32 0, 5
ret i32 %.2
ret i32 0
}
define void @main(i32,i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%.1 = add i32 0, 0
%.2 = icmp sgt i32 %.0, %.1
br i1 %.2, label %then1, label %else1
then1:
%.3 = add i32 0, 0
%.4 = load i8**, i8*** %args
%.5 = add i32 1, %.3
%.6 = getelementptr i8*, i8** %.4, i32 %.5
%.7 = load i8*, i8** %.6
%.8 = call i32  @atoi(i8* %.7)
%.9 = sitofp i32 %.8 to double
%.10 = call double @method_overload_double_double(double %.9)
br label %ifCont1
else1:
%.11 = add i32 0, 5
%.12 = sitofp i32 %.11 to double
%.13 = call double @method_overload_double_double(double %.12)
br label %ifCont1
ifCont1:
%.14 = or i1 false, true
%.15 = xor i32 %.14, -1
br i1 %.15, label %then2, label %else2
then2:
%.16 = call i32 (i8*, ...) @printf(i8* getelementptr ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont2
else2:
%.17 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont2
ifCont2:
%.18 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.4, i32 0, i32 0))
%a = alloca i32
%.19 = add i32 0, 22222
store i32 %.19, i32* %a
%d = alloca double
%.20 = fadd double 0.000000, 2.3233320000000000e+07
store double %.20, double* %d
%b = alloca i32
%.21 = add i32 0, 3
store i32 %.21, i32* %b
%.22 = load i32 , i32* %a
%.23 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.22)
%b1 = alloca i1
%.24 = or i1 false, true
store i1 %.24, i1* %b1
%.25 = load i32 , i32* %a
%.26 = load i32 , i32* %a
%.27 = add i32 %.25, %.26
%.28 = load i32 , i32* %a
%.29 = add i32 %.27, %.28
%.30 = add i32 0, 8
%.31 = add i32 0, 2
%.32 = srem i32 %.30, %.31
%.33 = add i32 %.29, %.32
%.34 = load double , double* %d
%.35 = add i32 0, 3
%.36 = sitofp i32 %.35 to double
%.37 = fdiv double %.34, %.36
%.38 = sitofp i32 %.33 to double
%.39 = fadd double %.38, %.37
%.40 = load i32 , i32* %a
%.41 = load double , double* %d
%.42 = sitofp i32 %.40 to double
%.43 = fmul double %.42, %.41
%.44 = fadd double %.39, %.43
%.45 = load double , double* %d
%.46 = fadd double %.44, %.45
%.47 = load i32 , i32* %a
%.48 = sitofp i32 %.47 to double
%.49 = fsub double %.46, %.48
%.50 = load i32 , i32* %a
%.51 = load i32 , i32* %b
%.52 = mul i32 %.50, %.51
%.53 = load double , double* %d
%.54 = fadd double 0.0, %.53
%.55 = sitofp i32 %.52 to double
%.56 = fdiv double %.55, %.54
%.57 = load i32 , i32* %a
%.58 = load i32 , i32* %b
%.59 = mul i32 %.57, %.58
%.60 = load double , double* %d
%.61 = fadd double 0.0, %.60
%.62 = sitofp i32 %.59 to double
%.63 = fdiv double %.62, %.61
%.64 = fmul double %.56, %.63
%.65 = fadd double %.49, %.64
%.66 = fadd double 0.000000, 2.2000000000000002e+00
%.67 = call double @method_overload_double_double(double %.66)
%.68 = fadd double %.65, %.67
%.69 = add i32 0, 1
%.70 = add i32 0, 1
%.71 = call i32 @method_overload_int_int_int(i32 %.69,i32 %.70)
%.72 = sitofp i32 %.71 to double
store double %.72, double* %d
%.73 = fadd double %.68, %.72
%.74 = add i32 0, 5
%.75 = call i32 @method_main_int_int(i32 %.74)
%.76 = sitofp i32 %.75 to double
%.77 = fadd double %.73, %.76
%.78 = add i32 0, 1
%.79 = sub i32 %.77, %.78
%.80 = load i8**, i8*** %args
%.81 = add i32 1, %.79
%.82 = getelementptr i8*, i8** %.80, i32 %.81
%.83 = load i8*, i8** %.82
%.84 = call i32  @atoi(i8* %.83)
%.85 = sitofp i32 %.84 to double
%.86 = fadd double %.77, %.85
%.87 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.86)
%.88 = call i32 (i8*, ...) @printf(i8* getelementptr ([5 x i8], [5 x i8]* @.str.5, i32 0, i32 0))
%.89 = load i32 , i32* %a
%.90 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.89)
%.91 = call i32 (i8*, ...) @printf(i8* getelementptr ([11 x i8], [11 x i8]* @.str.6, i32 0, i32 0))
%.92 = load i32 , i32* %a
%.93 = add i32 0, 2
%.94 = add i32 0, 2
%.95 = mul i32 %.93, %.94
%.96 = add i32 0, 3
%.97 = add i32 0, 5
%.98 = sdiv i32 %.96, %.97
%.99 = add i32 %.95, %.98
%.100 = add i32 0, 5
%.101 = call i32 @method_main_int_int(i32 %.100)
%.102 = add i32 %.99, %.101
%.103 = icmp sge i32 %.92, %.102
br i1 %.103, label %then3, label %else3
then3:
%.104 = load i32 , i32* %a
%.105 = add i32 0, 2
%.106 = icmp sle i32 %.104, %.105
br i1 %.106, label %then4, label %else4
then4:
%.107 = add i32 0, 2
%.108 = load i32 , i32* %a
%.109 = icmp sge i32 %.107, %.108
br i1 %.109, label %then5, label %else5
then5:
%.110 = add i32 0, 2
%.111 = load i32 , i32* %a
%.112 = icmp sle i32 %.110, %.111
br i1 %.112, label %then6, label %else6
then6:
%.113 = load i32 , i32* %a
%.114 = add i32 0, 2
%.115 = icmp eq i32 %.113, %.114
br i1 %.115, label %then7, label %else7
then7:
%.116 = add i32 0, 2
%.117 = load i32 , i32* %a
%.118 = icmp eq i32 %.116, %.117
br i1 %.118, label %then8, label %else8
then8:
%.119 = load i32 , i32* %a
%.120 = add i32 0, 2
%.121 = icmp sgt i32 %.119, %.120
br i1 %.121, label %then9, label %else9
then9:
%.122 = load i32 , i32* %a
%.123 = add i32 0, 2
%.124 = icmp slt i32 %.122, %.123
br i1 %.124, label %then10, label %else10
then10:
%.125 = add i32 0, 2
%.126 = load i32 , i32* %a
%.127 = icmp sgt i32 %.125, %.126
br i1 %.127, label %then11, label %else11
then11:
%.128 = add i32 0, 2
%.129 = load i32 , i32* %a
%.130 = icmp slt i32 %.128, %.129
br i1 %.130, label %then12, label %else12
then12:
%.131 = load i32 , i32* %a
%.132 = add i32 0, 2
%.133 = icmp ne i32 %.131, %.132
br i1 %.133, label %then13, label %else13
then13:
%.134 = add i32 0, 2
%.135 = load i32 , i32* %a
%.136 = icmp ne i32 %.134, %.135
br i1 %.136, label %then14, label %else14
then14:
br label %ifCont14
else14:
br label %ifCont14
ifCont14:
br label %ifCont13
else13:
br label %ifCont13
ifCont13:
br label %ifCont12
else12:
br label %ifCont12
ifCont12:
br label %ifCont11
else11:
br label %ifCont11
ifCont11:
br label %ifCont10
else10:
br label %ifCont10
ifCont10:
br label %ifCont9
else9:
br label %ifCont9
ifCont9:
br label %ifCont8
else8:
br label %ifCont8
ifCont8:
br label %ifCont7
else7:
br label %ifCont7
ifCont7:
br label %ifCont6
else6:
br label %ifCont6
ifCont6:
br label %ifCont5
else5:
br label %ifCont5
ifCont5:
br label %ifCont4
else4:
br label %ifCont4
ifCont4:
br label %ifCont3
else3:
br label %ifCont3
ifCont3:
%.137 = call i32 (i8*, ...) @printf(i8* getelementptr ([11 x i8], [11 x i8]* @.str.7, i32 0, i32 0))
%.138 = load double , double* %d
%.139 = add i32 0, 2
%.140 = sitofp i32 %.139 to double
%.141 = fcmp oge double %.138, %.140
br i1 %.141, label %then15, label %else15
then15:
%.142 = load double , double* %d
%.143 = add i32 0, 2
%.144 = sitofp i32 %.143 to double
%.145 = fcmp ole double %.142, %.144
br i1 %.145, label %then16, label %else16
then16:
%.146 = add i32 0, 2
%.147 = load double , double* %d
%.148 = sitofp i32 %.146 to double
%.149 = fcmp oge double %.148, %.147
br i1 %.149, label %then17, label %else17
then17:
%.150 = add i32 0, 2
%.151 = load double , double* %d
%.152 = sitofp i32 %.150 to double
%.153 = fcmp ole double %.152, %.151
br i1 %.153, label %then18, label %else18
then18:
%.154 = load double , double* %d
%.155 = add i32 0, 2
%.156 = sitofp i32 %.155 to double
%.157 = fcmp oeq double %.154, %.156
br i1 %.157, label %then19, label %else19
then19:
%.158 = add i32 0, 2
%.159 = load double , double* %d
%.160 = sitofp i32 %.158 to double
%.161 = fcmp oeq double %.160, %.159
br i1 %.161, label %then20, label %else20
then20:
%.162 = load double , double* %d
%.163 = add i32 0, 2
%.164 = sitofp i32 %.163 to double
%.165 = fcmp ogt double %.162, %.164
br i1 %.165, label %then21, label %else21
then21:
%.166 = load double , double* %d
%.167 = add i32 0, 2
%.168 = sitofp i32 %.167 to double
%.169 = fcmp olt double %.166, %.168
br i1 %.169, label %then22, label %else22
then22:
%.170 = add i32 0, 2
%.171 = load double , double* %d
%.172 = sitofp i32 %.170 to double
%.173 = fcmp ogt double %.172, %.171
br i1 %.173, label %then23, label %else23
then23:
%.174 = add i32 0, 2
%.175 = load double , double* %d
%.176 = sitofp i32 %.174 to double
%.177 = fcmp olt double %.176, %.175
br i1 %.177, label %then24, label %else24
then24:
%.178 = load double , double* %d
%.179 = add i32 0, 2
%.180 = sitofp i32 %.179 to double
%.181 = fcmp one double %.178, %.180
br i1 %.181, label %then25, label %else25
then25:
%.182 = add i32 0, 2
%.183 = load double , double* %d
%.184 = sitofp i32 %.182 to double
%.185 = fcmp one double %.184, %.183
br i1 %.185, label %then26, label %else26
then26:
br label %ifCont26
else26:
br label %ifCont26
ifCont26:
br label %ifCont25
else25:
br label %ifCont25
ifCont25:
br label %ifCont24
else24:
br label %ifCont24
ifCont24:
br label %ifCont23
else23:
br label %ifCont23
ifCont23:
br label %ifCont22
else22:
br label %ifCont22
ifCont22:
br label %ifCont21
else21:
br label %ifCont21
ifCont21:
br label %ifCont20
else20:
br label %ifCont20
ifCont20:
br label %ifCont19
else19:
br label %ifCont19
ifCont19:
br label %ifCont18
else18:
br label %ifCont18
ifCont18:
br label %ifCont17
else17:
br label %ifCont17
ifCont17:
br label %ifCont16
else16:
br label %ifCont16
ifCont16:
br label %ifCont15
else15:
br label %ifCont15
ifCont15:
%.186 = load double , double* %d
%.187 = fadd double 0.000000, 2.2000000000000002e+00
%.188 = fcmp oge double %.186, %.187
br i1 %.188, label %then27, label %else27
then27:
%.189 = load double , double* %d
%.190 = fadd double 0.000000, 2.2000000000000002e+00
%.191 = fcmp ole double %.189, %.190
br i1 %.191, label %then28, label %else28
then28:
%.192 = fadd double 0.000000, 2.2000000000000002e+00
%.193 = load double , double* %d
%.194 = fcmp oge double %.192, %.193
br i1 %.194, label %then29, label %else29
then29:
%.195 = fadd double 0.000000, 2.2000000000000002e+00
%.196 = load double , double* %d
%.197 = fcmp ole double %.195, %.196
br i1 %.197, label %then30, label %else30
then30:
%.198 = load double , double* %d
%.199 = fadd double 0.000000, 2.2000000000000002e+00
%.200 = fcmp oeq double %.198, %.199
br i1 %.200, label %then31, label %else31
then31:
%.201 = fadd double 0.000000, 2.2000000000000002e+00
%.202 = load double , double* %d
%.203 = fcmp oeq double %.201, %.202
br i1 %.203, label %then32, label %else32
then32:
%.204 = load double , double* %d
%.205 = fadd double 0.000000, 2.2000000000000002e+00
%.206 = fcmp ogt double %.204, %.205
br i1 %.206, label %then33, label %else33
then33:
%.207 = load double , double* %d
%.208 = fadd double 0.000000, 2.2000000000000002e+00
%.209 = fcmp olt double %.207, %.208
br i1 %.209, label %then34, label %else34
then34:
%.210 = fadd double 0.000000, 2.2000000000000002e+00
%.211 = load double , double* %d
%.212 = fcmp ogt double %.210, %.211
br i1 %.212, label %then35, label %else35
then35:
%.213 = fadd double 0.000000, 2.2000000000000002e+00
%.214 = load double , double* %d
%.215 = fcmp olt double %.213, %.214
br i1 %.215, label %then36, label %else36
then36:
%.216 = load double , double* %d
%.217 = fadd double 0.000000, 2.2000000000000002e+00
%.218 = fcmp one double %.216, %.217
br i1 %.218, label %then37, label %else37
then37:
%.219 = fadd double 0.000000, 2.2000000000000002e+00
%.220 = load double , double* %d
%.221 = fcmp one double %.219, %.220
br i1 %.221, label %then38, label %else38
then38:
br label %ifCont38
else38:
br label %ifCont38
ifCont38:
br label %ifCont37
else37:
br label %ifCont37
ifCont37:
br label %ifCont36
else36:
br label %ifCont36
ifCont36:
br label %ifCont35
else35:
br label %ifCont35
ifCont35:
br label %ifCont34
else34:
br label %ifCont34
ifCont34:
br label %ifCont33
else33:
br label %ifCont33
ifCont33:
br label %ifCont32
else32:
br label %ifCont32
ifCont32:
br label %ifCont31
else31:
br label %ifCont31
ifCont31:
br label %ifCont30
else30:
br label %ifCont30
ifCont30:
br label %ifCont29
else29:
br label %ifCont29
ifCont29:
br label %ifCont28
else28:
br label %ifCont28
ifCont28:
br label %ifCont27
else27:
br label %ifCont27
ifCont27:
%.222 = load i1 , i1* %b1
%.223 = or i1 false, true
%.224 = load double , double* %d
%.225 = fadd double 0.000000, 2.2000000000000002e+00
%.226 = fcmp oge double %.224, %.225
%.227 = and i1 %.223, %.226
%.228 = add i32 0, 2
%.229 = load double , double* %d
%.230 = sitofp i32 %.228 to double
%.231 = fcmp oge double %.230, %.229
%.232 = and i1 %.227, %.231
%.233 = fadd double 0.000000, 2.2000000000000002e+00
%.234 = load double , double* %d
%.235 = fcmp ole double %.233, %.234
%.236 = and i1 %.232, %.235
%.237 = fadd double 0.000000, 2.2000000000000002e+00
%.238 = load double , double* %d
%.239 = fadd double 0.000000, 2.2999999999999998e+00
%.240 = add i32 0, 2
store i32 %.240, i32* %a
%.241 = sitofp i32 %.240 to double
%.242 = fadd double %.239, %.241
%.243 = add i32 0, 2
%.244 = sitofp i32 %.243 to double
store double %.244, double* %d
%.245 = fadd double %.242, %.244
store double %.245, double* %d
%.246 = fadd double %.238, %.245
%.247 = fcmp oeq double %.237, %.246
%.248 = or i1 %.236, %.247
br i1 %.248, label %then39, label %else39
then39:
%.249 = or i1 false, true
%.250 = load i1 , i1* %b1
br i1 %.250, label %then40, label %else40
then40:
%.251 = load i1 , i1* %b1
%.252 = or i1 false, true
br i1 %.252, label %then41, label %else41
then41:
%.253 = or i1 false, true
%.254 = load i1 , i1* %b1
br i1 %.254, label %then42, label %else42
then42:
br label %ifCont42
else42:
br label %ifCont42
ifCont42:
br label %ifCont41
else41:
br label %ifCont41
ifCont41:
br label %ifCont40
else40:
br label %ifCont40
ifCont40:
br label %ifCont39
else39:
br label %ifCont39
ifCont39:
%.255 = load i1 , i1* %b1
%.256 = or i1 false, true
%.257 = and i1 %.255, %.256
%.258 = load i1 , i1* %b1
%.259 = or i1 %.257, %.258
%.260 = or i1 false, true
%.261 = load i1 , i1* %b1
%.262 = xor i32 %.261, -1
%.263 = or i1 false, true
%.264 = xor i1 %.262, %.263
%.265 = and i1 %.260, %.264
%.266 = or i1 %.259, %.265
br i1 %.266, label %then43, label %else43
then43:
%.267 = or i1 false, true
%.268 = load i1 , i1* %b1
%.269 = and i1 %.267, %.268
%.270 = or i1 false, true
%.271 = or i1 %.269, %.270
%.272 = load i1 , i1* %b1
%.273 = or i1 false, true
%.274 = load i1 , i1* %b1
%.275 = xor i32 %.274, -1
%.276 = xor i1 %.273, %.275
%.277 = and i1 %.272, %.276
%.278 = or i1 %.271, %.277
br i1 %.278, label %then44, label %else44
then44:
br label %ifCont44
else44:
br label %ifCont44
ifCont44:
br label %ifCont43
else43:
br label %ifCont43
ifCont43:
%.279 = call i32 (i8*, ...) @printf(i8* getelementptr ([11 x i8], [11 x i8]* @.str.8, i32 0, i32 0))
%.280 = load i32 , i32* %a
%.281 = load double , double* %d
%.282 = fsub double 0.0, %.281
%.283 = sitofp i32 %.280 to double
%.284 = fmul double %.283, %.282
%.285 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.284)
%.286 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.9, i32 0, i32 0))
%.287 = or i1 false, true
%.288 = load i1 , i1* %b1
%.289 = xor i32 %.288, -1
%.290 = xor i1 %.287, %.289
br i1 %.290, label %then45, label %else45
then45:
%.291 = call i32 (i8*, ...) @printf(i8* getelementptr ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont45
else45:
%.292 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont45
ifCont45:
%.293 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.10, i32 0, i32 0))
%d1 = alloca double
%.294 = fadd double 0.000000, 1.1000000000000001e+00
%.295 = sitofp i32 %.293 to double
%.296 = fadd double %.295, %.294
%.297 = add i32 0, 3
%.298 = sitofp i32 %.297 to double
%.299 = call double @method_overload_double_double(double %.298)
%.300 = fadd double %.296, %.299
%.301 = add i32 0, 3
%.302 = add i32 0, 3
%.303 = mul i32 %.301, %.302
%.304 = sitofp i32 %.303 to double
%.305 = fadd double %.300, %.304
%.306 = add i32 0, 2
%.307 = sitofp i32 %.306 to double
%.308 = fadd double %.305, %.307
%.309 = add i32 0, 2
%.310 = sitofp i32 %.309 to double
%.311 = fadd double %.308, %.310
%.312 = add i32 0, 2
%.313 = sub i32 0, %.312
%.314 = sitofp i32 %.313 to double
%.315 = fadd double %.311, %.314
%.316 = add i32 0, 3
%.317 = add i32 0, 3
%.318 = sdiv i32 %.316, %.317
%.319 = sitofp i32 %.318 to double
%.320 = fadd double %.315, %.319
store double %.320, double* %d1
%i = alloca i32
%.321 = add i32 0, 0
store i32 %.321, i32* %i
%j = alloca i32
%.322 = add i32 0, 0
store i32 %.322, i32* %j
%.323 = call i32 (i8*, ...) @printf(i8* getelementptr ([14 x i8], [14 x i8]* @.str.11, i32 0, i32 0))
br label %while1
while1:
br label %while2
while2:
br label %while3
while3:
%.324 = load i32 , i32* %i
%.325 = add i32 0, 1
%.326 = add i32 %.324, %.325
store i32 %.326, i32* %i
%.327 = load i32 , i32* %j
%.328 = add i32 0, 1
%.329 = add i32 %.327, %.328
store i32 %.329, i32* %j
%.330 = load i32 , i32* %i
%.331 = add i32 0, 10
%.332 = icmp eq i32 %.330, %.331
br i1 %.332, label %then46, label %else46
then46:
%.333 = load i32 , i32* %j
%.334 = add i32 0, 9
%.335 = icmp eq i32 %.333, %.334
br i1 %.335, label %then47, label %else47
then47:
br label %ifCont47
else47:
br label %ifCont47
ifCont47:
br label %ifCont46
else46:
br label %ifCont46
ifCont46:
%.336 = add i32 0, 20
%.337 = load i32 , i32* %j
%.338 = icmp sgt i32 %.336, %.337
%.339 = load i32 , i32* %i
%.340 = add i32 0, 10
%.341 = icmp slt i32 %.339, %.340
%.342 = and i1 %.338, %.341
br i1 %.342, label %while3, label %whileCont3
whileCont3:
%.343 = add i32 0, 10
%.344 = load i32 , i32* %i
%.345 = icmp sgt i32 %.343, %.344
br i1 %.345, label %while2, label %whileCont2
whileCont2:
%.346 = load i32 , i32* %i
%.347 = add i32 0, 10
%.348 = icmp slt i32 %.346, %.347
br i1 %.348, label %while1, label %whileCont1
whileCont1:
ret void 
}
