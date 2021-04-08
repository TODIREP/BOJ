import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = readLine().toInt()
    val operation = readLine()
    val nums = mutableListOf<Int>()
    val opers = mutableListOf<Char>()
    repeat(n) { index ->
        when (index % 2) {
            0 -> nums.add(operation[index] - '0')
            1 -> opers.add(operation[index])
        }
    }
    fun cal(a: Int, b: Int, oper: Char): Int {
        return when (oper) {
            '*' -> a * b
            '+' -> a + b
            else -> a - b
        }
    }
    var answer = Int.MIN_VALUE
    val used = BooleanArray(n)
    val operSize = opers.size
    fun search(cur: Int) {
        if (cur >= operSize) {
            val num = mutableListOf<Int>()
            val oper = mutableListOf<Char>()
            num.add(nums[0])
            var numIndex = 1
            repeat(operSize) { index ->
                when (used[index]) {
                    true -> {
                        num[num.size - 1] = cal(num[num.size - 1], nums[numIndex], opers[index])
                    }
                    false -> {
                        num.add(nums[numIndex])
                        oper.add(opers[index])
                    }
                }
                numIndex++
            }
            var current = num[0]
            val size = oper.size
            repeat(size) { index ->
                current = cal(current, num[index + 1], oper[index])
            }
            answer = answer.coerceAtLeast(current)
            return
        }
        used[cur] = true
        search(cur + 2)
        used[cur] = false
        search(cur + 1)
    }
    search(0)
    bw.write("$answer")
    bw.close()
}
fun main() {
    solution()
}