<script lang="ts">
	import { PUBLIC_MQTT_BROKER_PORT, PUBLIC_MQTT_BROKER_URL } from '$env/static/public';
	import { Loader } from 'lucide-svelte';
	import { Client } from 'paho-mqtt';
	import type { PageServerData } from './$types';
	import { onMount } from 'svelte';

	export let data: PageServerData;
	let client: Client;

	let currentTemp = 0;
	$: displayTemp = currentTemp.toFixed(1);
	$: isConnected = true;

	onMount(() => {
		const clientId = 'clientId-' + Math.random();
		client = new Client(PUBLIC_MQTT_BROKER_URL, Number(PUBLIC_MQTT_BROKER_PORT), clientId);

		client.connect({
			useSSL: data.environment === 'production',
			onSuccess: () => {
				client.subscribe('ats-temp/#');
				isConnected = false;
			},
			reconnect: true
		});

		// called when a message arrives
		client.onMessageArrived = ({ payloadString }) => {
			console.log(payloadString);
			currentTemp = Number(payloadString);
		};
	});
</script>

<svelte:head>
	<title>Arduino Temperature Sensor</title>
</svelte:head>

<div class="text-center flex flex-col gap-8">
	<div class="flex flex-col justify-center items-center">
		<p class="text-xl">อุณหภูมิในขณะนี้</p>
		{#if isConnected}
			<Loader class="animate-spin w-32 h-32" />
		{:else}
			<h4 class="font-bold text-8xl">{displayTemp}°C</h4>
		{/if}
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
