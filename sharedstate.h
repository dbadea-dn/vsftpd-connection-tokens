#ifndef VSF_SHAREDSTATE_H
#define VSF_SHAREDSTATE_H

#include "builddefs.h"
#include "session.h"

void shared_state_setup(struct vsf_session* p_sess, const char *path);
void shared_state_lock(struct vsf_session* p_sess);
void shared_state_unlock(struct vsf_session* p_sess);

#endif /* VSF_SHAREDSTATE_H */
