class Solution {
    fun abs(a: Long) = if (a < 0) -a else a
    val number = mutableListOf<Long>()
    val operation = mutableListOf<Char>()
    var answer: Long = 0
    val opers = CharArray(3)
    val check = BooleanArray(3) { false }
    val oper = charArrayOf('+', '-', '*')
    
    fun calcul(a: Long, b: Long, op: Char): Long {
        return when (op) {
            '+' -> a + b
            '-' -> a - b
            else -> a * b
        }
    }
    fun cal(numbers: MutableList<Long>, insts: MutableList<Char>, it: Int) {
        if (it == 3) {
            answer = answer.coerceAtLeast(abs(numbers[0]))
            return
        }
        val nums = mutableListOf<Long>()
        val inst = mutableListOf<Char>()
        
        nums.add(numbers[0])
        val size = numbers.size
        for (n in 1 until size) {
            if (insts[n - 1] == opers[it]) {
                nums[nums.size - 1] = calcul(nums[nums.size - 1], numbers[n], insts[n - 1])
            } else {
                nums.add(numbers[n])
                inst.add(insts[n - 1])
            }
        }
        return cal(nums, inst, it + 1)
    }
    fun makePriority(cnt: Int) {
        if (cnt == 3) {
            cal(number, operation, 0)
            return
        }
        for (it in 0 until 3) {
            if (check[it]) continue
            check[it] = true
            opers[cnt] = oper[it]
            makePriority(cnt + 1)
            check[it] = false
        }
    }
    fun solution(expression: String): Long {
        val size = expression.length
        var before = 0
        for (it in 0 until size) {
            if (expression[it] in "+-*") {
                number.add(expression.substring(before, it).toLong())
                operation.add(expression[it])
                before = it + 1
            }
        }
        number.add(expression.substring(before, size).toLong())
        makePriority(0)
        return answer
    }
}