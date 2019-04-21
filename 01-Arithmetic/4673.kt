fun main(args: Array<String>) {
    val isSelfNum = BooleanArray(10001)
    var temp = 0
    for(i in 0..10000) {
        temp = i
        i.toString().forEach {
        	temp += it.toInt() - '0'.toInt()
        }
        if (temp < 10001)
        	isSelfNum[temp] = true
    }
    for(i in 0..10000) {
        if (!isSelfNum[i])
        	println("$i")
    }
}