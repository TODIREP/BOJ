import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val lc = readLine().split(" ").map { it.toInt() }
    val l = lc[0]
    val c = lc[1]
    val word: MutableList<String> = readLine().split(" ").sorted().toMutableList()

    fun search(start: Int, target: String) {
        if (target.length == l) {
            var moem = 0
            var jaem = 0

            for (i in 0 until l) {
                when (target[i] in "aeiou") {
                    true -> moem++
                    else -> jaem++
                }
            }

            if ((moem > 0) and (jaem > 1)) {
                bw.write("$target\n")
            }
            return
        }
        for (i in start until c) {
            search(i + 1, target + word[i])
        }
    }
    search(0, "")
    bw.close()
}

fun main() {
    solution()
}