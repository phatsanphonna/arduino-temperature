<svelte:head>
	<title>เกี่ยวกับ | Arduino Temperature Sensor</title>
</svelte:head>

<div class="w-full">
	<h1 class="scroll-m-20 text-4xl font-extrabold tracking-tight lg:text-5xl">
		Arduino Temperature Sensor
	</h1>

	<h2
		class="mt-10 scroll-m-20 border-b pb-2 text-3xl font-semibold tracking-tight transition-colors first:mt-0"
	>
		เกี่ยวกับโปรเจคนี้
	</h2>
	<p class="leading-7 [&:not(:first-child)]:mt-6">
		โปรเจคของเราได้ทำเกี่ยวกับการเตือนภัยของสภาพอากาศที่ร้อนมากในปัจจุบันซึ่งเป็นเหตุที่ทำให้มนุษย์เกิดโรคฮีทสโตรกที่อันตรายต่อชีวิต
		ณ
		ปัจจุบันโรคนี้มีอัตราความเสี่ยงเสียชีวิตสูงขึ้นในทุกปีเราจึงอยากนำความรู้ที่เรียนมาประยุกต์ใช้ในการทำโปรเจคครั้งนี้
		โดยการนำความรู้จาก Arduino มาต่อวงจรเชื่อมเซนเซอร์เขียนโค้ดทำการแจ้งเตือนและยังใช้ MQTT
		เชื่อมต่ออีกด้วย
		เราหวังเป็นอย่างยิ่งว่าการทำโปรเจคเตือนสภาพอากาศครั้งนี้จะทำให้มนุษย์ในอัตราการเสียชีวิตลดน้อยลง
	</p>

	<h2
		class="mt-10 scroll-m-20 border-b pb-2 text-3xl font-semibold tracking-tight transition-colors first:mt-0"
	>
		คำอธิบายโครงงาน
	</h2>
	<p class="leading-7 [&:not(:first-child)]:mt-6">
		โปรเจค เกี่ยวกับ notification แจ้งเตือนสภาพอากาศอุณหภูมิที่สูงเกินตั้งแต่ 35
		องศาเซลเซียสเป็นต้นไปควรที่จะระมัดระวังตัวเอง โดยใช้ Arduino ในการต่อวงจรเขียนโค้ดและใช้ MQTT
		ในการเชื่อมต่อสื่อสารระหว่าง Arduino ไปยังเว็บไซต์
		ให้ทำงานแจ้งเตือนหากมีสภาพอากาศที่เสี่ยงต่อการเกิดโรคฮีทสโตรก
	</p>

	<h2
		class="mt-10 scroll-m-20 border-b pb-2 text-3xl font-semibold tracking-tight transition-colors first:mt-0"
	>
		Source Code
	</h2>
	<p class="leading-7 [&:not(:first-child)]:mt-6">
		Source code ของโปรเจคนี้สามารถดูได้ที่ <a
			target="_blank"
			class="underline"
			href="https://github.com/phatsanphonna/arduino-temperature">GitHub</a
		>
	</p>

	<h2
		class="mt-10 scroll-m-20 border-b pb-2 text-3xl font-semibold tracking-tight transition-colors first:mt-0"
	>
		วิดีโอตัวอย่าง
	</h2>
</div>
