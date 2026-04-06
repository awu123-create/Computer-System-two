/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 * 曾子煜 2024150078
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
  int result = ~(~(x & ~y) & ~(~x & y));
  return result;
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
  return 1 << 31;
}
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x)
{
  // 判断一个数是否为最大二进制数
  // x == 0x7FFFFFFF 时返回 1，否则返回 0

  return !((x + 1) ^ ~x) & !!(x + 1);
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
  // 判断一个数的所有奇数位是否都为 1
  int mask = (0xAA << 8) | 0xAA;
  mask = (mask << 16) | mask;
  // 将x和mask进行按位与
  return !((x & mask) ^ mask);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
  // 返回负数
  return ~x + 1;
}
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
  // 判断一个数是不是 ASCII 码中 '0' 到 '9' 的范围
  int min_negate = ~0x30 + 1;
  int max_check = ~x + 1 + 0x39, min_check = min_negate + x;
  int max_sign = max_check >> 31, min_sign = min_check >> 31;
  return !(max_sign | min_sign);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
  // 实现三元运算符 x ? y : z 的功能
  // 当 x 不为 0 时返回 y，否则返回 z
  int notZero = !!x;
  int mask = ~notZero + 1;
  return (y & mask) | (z & ~mask);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
  int x_sign = (x >> 31) & 1;
  int y_sign = (y >> 31) & 1;
  int sign_diff = x_sign ^ y_sign;
  int diff_sign = ((y + (~x + 1)) >> 31) & 1;
  return (sign_diff & x_sign) | (!sign_diff & !diff_sign);
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
{
  return ((x | (~x + 1)) >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
  // 用补码表示一个数需要的最少位数
  int sign = x >> 31;
  int abs_x = x ^ sign;

  // 现在需要开始找出 abs_x 的最高位 1 的位置
  // cnt负责数值部分最高位的位置计数
  int cnt = 1, temp = 0;
  temp = (!!(abs_x >> 16)) << 4;
  cnt = cnt + temp;
  abs_x = abs_x >> temp;

  temp = (!!(abs_x >> 8)) << 3;
  cnt = cnt + temp;
  abs_x = abs_x >> temp;

  temp = (!!(abs_x >> 4)) << 2;
  cnt = cnt + temp;
  abs_x = abs_x >> temp;

  temp = (!!(abs_x >> 2)) << 1;
  cnt = cnt + temp;
  abs_x = abs_x >> temp;

  temp = !!(abs_x >> 1);
  cnt = cnt + temp;
  return cnt + !!(x ^ sign);
}
// float
/*
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf)
{
  // 计算2*f的位级表示，当参数为NaN时返回参数本身
  // 1. 先提取出符号位、指数位和尾数位
  unsigned sign = (uf & 0x80000000) >> 31;
  unsigned exp = (uf & 0x7F800000) >> 23;
  unsigned frac = (uf & 0x007FFFFF);

  // 2. 判断NaN和无穷大
  if (exp == 0xFF)
  {
    return uf;
  }

  // 3. 判断规格数和非规格数
  if (exp != 0)
  {
    exp += 1;
    if (exp == 0xFF)
    {
      frac = 0;
    }
  }
  else
  {
    frac = frac << 1;
    if (frac & 0x00800000)
    {
      exp = 1;
      frac = frac & 0x007FFFFF;
    }
  }
  return (sign << 31) | (exp << 23) | frac;
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x)
{
  // 返回float(x)的位级表示
  unsigned sign = 0;
  unsigned abs_x = 0;
  int cnt = 0;
  unsigned temp = 0;
  int exp = 0;
  unsigned frac = 0;

  if (x == 0)
  {
    return 0;
  }

  sign = x & 0x80000000;
  abs_x = x;
  if (sign)
  {
    abs_x = -x;
  }
  cnt = 0;

  // 找出abs_x的最高位1的位置
  temp = abs_x;
  while (temp)
  {
    temp = temp >> 1;
    cnt = cnt + 1;
  }
  exp = cnt + 126; // exp = cnt - 1 + 127

  if (cnt <= 24)
  {
    // 不需要舍入，直接把最高位1后面的内容对齐到尾数字段
    frac = abs_x << (24 - cnt);
  }
  else
  {
    // 需要保留前24位（隐藏位1 + 23位frac）
    int shift = cnt - 24;
    int frac_part = abs_x >> shift; // 前24位
    int round_bit = (abs_x >> (shift - 1)) & 1;
    int rest = abs_x & ((1 << (shift - 1)) - 1);

    if (round_bit && (rest || (frac_part & 1)))
    {
      frac_part += 1;
    }

    if (frac_part >> 24)
    {
      exp += 1;
      frac_part >>= 1;
    }
    frac = frac_part & 0x007FFFFF;
  }

  return sign | (exp << 23) | (frac & 0x007FFFFF);
}
/*
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf)
{
  // 返回 (int)f 的位级表示
  unsigned sign = uf & 0x80000000;
  unsigned exp = (uf & 0x7F800000) >> 23;
  unsigned frac = uf & 0x007FFFFF;
  unsigned result = 0;

  int E = exp - 127;
  if (exp == 0xFF || E > 30)
  {
    return 0x80000000u;
  }
  else if (E < 0)
  {
    return 0;
  }
  else if (E > 23)
  {
    result = (1 << 23) | frac;
    if (sign)
    {
      return -(result << (E - 23));
    }
    else
    {
      return result << (E - 23);
    }
  }
  else
  {
    result = (1 << 23) | frac;
    if (sign)
    {
      return -(result >> (23 - E));
    }
    else
    {
      return result >> (23 - E);
    }
  }
}
