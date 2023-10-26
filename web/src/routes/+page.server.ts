import { NODE_ENV } from '$env/static/private';
import type { PageServerLoad } from './$types';

export const load: PageServerLoad = async () => {
    return {
        environment: NODE_ENV
    }
};