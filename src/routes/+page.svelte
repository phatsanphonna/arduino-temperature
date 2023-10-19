<script lang="ts">
	import { Client } from 'paho-mqtt';

	let client: Client;
	let currentTemp = -50.6;
	$: displayTemp = currentTemp.toFixed(0);

	client = new Client('broker.hivemq.com', 8000, 'clientId-' + Math.random());

	client.connect({
		onSuccess: () => {
			client.subscribe('ssuniie/#');
		},
		reconnect: true
	});

	// called when a message arrives
	client.onMessageArrived = (message) => {
		currentTemp = Number(message.payloadString);
	};
</script>

<svelte:head>
	<title>Arduino Temperature Sensor</title>
</svelte:head>

<div class="text-center flex flex-col gap-8">
	<div class="flex flex-col">
		<p class="text-xl">อุณหภูมิในขณะนี้</p>
		<h4 class="font-bold text-8xl">{displayTemp}°C</h4>
	</div>

	<span class="text-sm text-muted-foreground">ระบบจะทำการอ่านค่าทุก ๆ 5 วินาที</span>
</div>

<hr class="w-full" />

<div>
	<h3 class="scroll-m-20 text-2xl font-semibold tracking-tight">
		คำแนะนำสำหรับอุณหภูมิ {displayTemp} องศาเซลเซียส (อบอุ่น)
	</h3>

	<p class="leading-7 [&:not(:first-child)]:mt-6">
		Lorem, ipsum dolor sit amet consectetur adipisicing elit. Consequatur architecto mollitia dolore
		ad, delectus, asperiores explicabo quis rem blanditiis magnam corrupti esse quod. Pariatur
		iusto, nostrum quia nihil sint labore.Lorem, ipsum dolor sit amet consectetur adipisicing elit.
		Consequatur architecto mollitia dolore ad, delectus, asperiores explicabo quis rem blanditiis
		magnam corrupti esse quod. Pariatur iusto, nostrum quia nihil sint labore.Lorem, ipsum dolor sit
		amet consectetur adipisicing elit. Consequatur architecto mollitia dolore ad, delectus,
		asperiores explicabo quis rem blanditiis magnam corrupti esse quod. Pariatur iusto, nostrum quia
		nihil sint labore.Lorem, ipsum dolor sit amet consectetur adipisicing elit. Consequatur
		architecto mollitia dolore ad, delectus, asperiores explicabo quis rem blanditiis magnam
		corrupti esse quod. Pariatur iusto, nostrum quia nihil sint labore.Lorem, ipsum dolor sit amet
		consectetur adipisicing elit. Consequatur architecto mollitia dolore ad, delectus, asperiores
		explicabo quis rem blanditiis magnam corrupti esse quod. Pariatur iusto, nostrum quia nihil sint
		labore.
	</p>
</div>
