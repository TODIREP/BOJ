import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    fun getInput() = readLine().split(" ")

    val (n, k) = getInput().map(String::toInt)
    val arr = Array(n) { BooleanArray(n) { false } }
    repeat(k) {
        val (prev, next) = getInput().map(String::toInt)
        arr[prev - 1][next - 1] = true
    }

    repeat(n) { check ->
        repeat(n) start@ { x ->
            if (x == check) return@start
            repeat(n) target@ { y ->
                if ((y == check) or (y == x)) return@target
                if (arr[x][check] and arr[check][y]) {
                    arr[x][y] = true
                }
            }
        }
    }
    
    val s = readLine().toInt()
    repeat(s) {
        var (prev, next) = getInput().map(String::toInt)
        prev--
        next--
        when {
            arr[prev][next] == arr[next][prev] -> bw.write("0\n")
            arr[prev][next] -> bw.write("-1\n")
            arr[next][prev] -> bw.write("1\n")
        }
    }
    bw.close()
}
fun main() {
    solution()
}