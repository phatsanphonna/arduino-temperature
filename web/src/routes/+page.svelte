<script lang="ts">
	import { PUBLIC_MQTT_BROKER_PORT, PUBLIC_MQTT_BROKER_URL } from '$env/static/public';
	import { Loader } from 'lucide-svelte';
	import { Client } from 'paho-mqtt';
	import type { PageServerData } from './$types';
	import { onMount } from 'svelte';
	import { chill, cold, hot, snow, warm } from './quotes';

	import { marked as mark } from 'marked';

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
		<p class="text-xl">Current temperature</p>
		{#if isConnected}
			<Loader class="animate-spin w-32 h-32" />
		{:else}
			<h4 class="font-bold text-8xl">{displayTemp}°C</h4>
		{/if}
	</div>
</div>

<hr class="w-full" />

<div>
	<h3 class="scroll-m-20 text-2xl font-semibold tracking-tight">
		Recommendation for {displayTemp}°C
	</h3>

	<article
		class="white-space: pre-wrap;
 	prose lg:prose-xl leading-7 [&:not(:first-child)]:mt-6"
	>
		{#if currentTemp >= 28 && currentTemp < 35}
			{@html mark(warm)}
		{:else if currentTemp >= 20 && currentTemp < 28}
			{@html mark(chill)}
		{:else if currentTemp >= 0 && currentTemp < 20}
			{@html mark(cold)}
		{:else if currentTemp < 0}
			{@html mark(snow)}
		{:else if currentTemp >= 35}
			{@html mark(hot)}
		{/if}
	</article>
</div>
