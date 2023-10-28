<svelte:head>
	<title>เกี่ยวกับ | Arduino Temperature Sensor</title>
</svelte:head>

<div class="w-full">
	<h1 class="scroll-m-20 text-4xl font-extrabold tracking-tight lg:text-5xl">
		Arduino Temperature Sensor
	</h1>
	<p class="leading-7 [&:not(:first-child)]:mt-6">
		โครงงานนี้ได้ศึกษาพฤติกรรมของมนุษย์ ที่ต้องการความสะดวกสบาย
		ต้องการเทคโนโลยีที่จะช่วยอำนวยความสะดวกในชีวิตประจำวันเพื่อป้องกันโรคฮีทสโตรกโรคอันตรายที่มนุษย์ไม่ระมัดระวังตัว
		เนื่องจากประเทศไทยช่วงระยะเวลาฤดูร้อนมีสภาพแวดล้อมอากาศโดยรอบที่มีอุณหภูมิสูงมาก
		และมนุษย์ไม่พึงระวังตัวต่อโรคฮีทสโตรกภัยเงียบนี้ได้ ทำให้ ณ
		ปัจจุบันมีคนเสียชีวิตจากโรคนี้เพิ่มขึ้นในทุกๆปี พวกเราจึงคิดที่จะนำ arduino มาใช้ในการช่วย
		ในเรื่องของการเตือนอุณหภูมิอากาศภายนอกที่สูงจนอาจจะทำให้เกิดอัตรายต่อชีวิตมนุษย์ได้
	</p>
	<p class="leading-7 [&:not(:first-child)]:mt-6">
		ผลการดำเนินงาน
		พวกเราเริ่มจากการที่เรามีไอเดียที่อยากการแจ้งเตือนอุณหภูมิอากาศเพื่อลดความเสี่ยงของโรคฮีสสโตกอันตรายต่อชีวิต
		ได้ทำการหาข้อมูลอุณหภูมิที่อัตรายต่อการเกิดโรคนี้ขึ้นได้ จากนั้นทำการต่อวงจร เขียนโค้ดและใช้
		MQTT ในการเชื่อมต่อการสื่อสารระหว่างarduino และของ Websiteราตามที่เราได้หาข้อมูล
		เกิดข้อผิดพลาดระหว่างการทำงานเล็กน้อยแต่พวกเราสามารถแก้ไขปัญหาและสามารถทำชิ้นงานนี้ได้สำเร็จตามเวลาที่กำหนด
	</p>

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
	<div class="mt-10 flex justify-center items-center">
		<iframe
			width="560"
			height="315"
			src="https://www.youtube.com/embed/d_INH0gorT4?si=HlMlx1Kv57cNga_E"
			title="YouTube video player"
			frameborder="0"
			allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
			allowfullscreen
		/>
	</div>

	<h2
		class="mt-10 scroll-m-20 border-b pb-2 text-3xl font-semibold tracking-tight transition-colors first:mt-0"
	>
		สมาชิกภายในกลุ่ม
	</h2>
	<ul class="my-6 ml-6 list-disc [&>li]:mt-2">
		<li><b>65070144</b> พรพัฒน์ ธนทัตธาดา</li>
		<li><b>65070171</b> ภัทร์สรรพ์พร นครานุรักษ์</li>
		<li><b>65070225</b> ศุภธัช สุวัฒโน</li>
	</ul>
</div>
