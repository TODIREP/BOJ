import java.util.*
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    var number = 0
    val m = br.readLine().toInt()
    val result = StringBuilder()
    for (it in 0 until m) {
        val token = StringTokenizer(br.readLine())
        when (token.nextToken()) {
            "add" -> {
                val num = (1 shl (token.nextToken().toInt() - 1))
                if (number and num == 0) number = number or num
            }
            "remove" -> {
                val num = (1 shl (token.nextToken().toInt() - 1))
                if (number and num == num) number = number and num.inv()
            }
            "check" -> {
                val num = (1 shl (token.nextToken().toInt() - 1))
                result.append(
                    when (number and num == num) {
                        true -> "1\n"
                        false -> "0\n"
                    }
                )
            }
            "toggle" -> {
                val num = (1 shl (token.nextToken().toInt() - 1))
                number =
                    if (number and num == num) number and num.inv()
                    else number or num
            }
            "all" -> number = (1 shl 21) - 1
            "empty" -> number = 0
        }
    }
    bw.write(result.toString())
    bw.close()
}