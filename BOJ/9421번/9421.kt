import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = readLine()!!.toInt()
    val check = BooleanArray(n + 1) { false }
    val result = BooleanArray(n + 1) { false }
    fun nextNum(num: Int): Int {
        var start = num
        var cur = 0
        while (start > 0) {
            cur += (start % 10) * (start % 10)
            start /= 10
        }
        return cur
    }
    fun search(num: Int) {
        val arr = TreeSet<Int>()
        arr.add(num)
        var valid = true
        fun find(current: Int) {
            if (current == 1) return
            if (arr.contains(current)) {
                valid = false
                return
            }
            arr.add(current)
            return find(nextNum(current))
        }
        find(nextNum(num))
        if (valid) {
            arr.forEach {
                if (it <= n) result[it] = true
            }
        }
    }
    for (num in 2..n) {
        if (check[num]) continue
        for (number in num * 2..n step(num)) {
            if (check[number]) continue
            check[number] = true
        }
        if (!result[num]) search(num)
    }

    for (num in 2..n) {
        if (!check[num] and result[num]) bw.write("$num\n")
    }
    bw.close()
}