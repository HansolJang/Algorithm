import kotlin.math.min

fun main(args: Array<String>) {
    val str = readLine()!!
    var count = 0
    var i = 0
    while(i < str.length) {
        if (str.substring(i, min(i + 2, str.length))
                in listOf("c=", "c-", "d-", "lj", "nj", "s=", "z=" )) {
            count++
            i += 2
            continue
        }
        if (str.substring(i, min(i + 3, str.length)) == "dz=") {
            count++
            i += 3
            continue
        }
        count++
        i++
    }
    println("${count}")
}